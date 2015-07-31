/****************************************************************************
 * This file is part of Qt AccountsService Addon.
 *
 * Copyright (C) 2012-2015 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * Author(s):
 *    Pier Luigi Fiorini
 *
 * $BEGIN_LICENSE:LGPL2.1+$
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $END_LICENSE$
 ***************************************************************************/

#include <QtCore/QDebug>
#include <QtDBus/QDBusPendingCallWatcher>

#include "accountsmanager.h"
#include "accountsmanager_p.h"

namespace QtAccountsService {

/*
 * AccountsManagerPrivate
 */

AccountsManagerPrivate::AccountsManagerPrivate(const QDBusConnection &bus)
{
    interface = new OrgFreedesktopAccountsInterface(
        QStringLiteral("org.freedesktop.Accounts"),
        QStringLiteral("/org/freedesktop/Accounts"),
        bus);
}

AccountsManagerPrivate::~AccountsManagerPrivate()
{
    delete interface;
}

void AccountsManagerPrivate::_q_userAdded(const QDBusObjectPath &path)
{
    Q_Q(AccountsManager);
    Q_EMIT q->userAdded(new UserAccount(path.path(), interface->connection()));
}

void AccountsManagerPrivate::_q_userDeleted(const QDBusObjectPath &path)
{
    Q_Q(AccountsManager);
    Q_EMIT q->userDeleted(new UserAccount(path.path(), interface->connection()));
}

/*!
    \class AccountsManager
    \brief AccountsManager provides the backend for user management.

    The AccountsManager class allows for querying and manipiulating user
    account information.

    \author Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
*/

/*!
    Constructs a AccountsManager object.
*/
AccountsManager::AccountsManager(const QDBusConnection &bus)
    : d_ptr(new AccountsManagerPrivate(bus))
{
    d_ptr->q_ptr = this;

    connect(d_ptr->interface, SIGNAL(UserAdded(QDBusObjectPath)),
            this, SLOT(_q_userAdded(QDBusObjectPath)));
    connect(d_ptr->interface, SIGNAL(UserDeleted(QDBusObjectPath)),
            this, SLOT(_q_userDeleted(QDBusObjectPath)));
}

/*!
    Destroy a AccountsManager object.
*/
AccountsManager::~AccountsManager()
{
    delete d_ptr;
}

/*!
    Caches a user account, so that it shows up in listCachedUsers() output.
    The user name may be a remote user, but the system must be able to lookup
    the user name and resolve the user information.

    A userCached() signal with a UserAccount pointer will be emitted as soon
    as the user account has been cached by AccountsService.

    \param userName The user name for the user.
*/
void AccountsManager::cacheUser(const QString &userName)
{
    Q_D(AccountsManager);

    QDBusPendingCall call = d->interface->CacheUser(userName);
    QDBusPendingCallWatcher *watcher = new QDBusPendingCallWatcher(call, this);
    connect(watcher, &QDBusPendingCallWatcher::finished, this, [=](QDBusPendingCallWatcher *w) {
        QDBusPendingReply<QDBusObjectPath> reply = *w;
        w->deleteLater();
        if (reply.isError()) {
            QDBusError error = reply.error();
            qWarning("Couldn't cache user %s: %s",
                     userName.toUtf8().constData(),
                     error.errorString(error.type()).toUtf8().constData());
        } else {
            QDBusObjectPath path = reply.argumentAt<0>();
            if (!path.path().isEmpty())
                Q_EMIT userCached(new UserAccount(path.path(), d->interface->connection()));
        }
    });
}

/*!
    Releases all metadata about a user account, including icon, language and session.
    If the user account is from a remote server and the user has never logged in
    before, then that account will no longer show up in listCachedUsers() output.

    \param userName The user name for the user.
*/
void AccountsManager::uncacheUser(const QString &userName)
{
    Q_D(AccountsManager);

    d->interface->UncacheUser(userName);
}

/*!
    Releases all metadata about a user account, including icon, language and session.
    If the user account is from a remote server and the user has never logged in
    before, then that account will no longer show up in listCachedUsers() output.

    \param account The account for the user.
*/
void AccountsManager::uncacheUser(UserAccount *account)
{
    return uncacheUser(account->userName());
}

/*!
    Returns a list of user accounts.

    \param systemUsers If true, returns also system users.
*/
UserAccountList AccountsManager::listCachedUsers()
{
    Q_D(AccountsManager);

    UserAccountList list;

    QDBusPendingReply< QList<QDBusObjectPath> > reply = d->interface->ListCachedUsers();
    reply.waitForFinished();

    if (reply.isError()) {
        QDBusError error = reply.error();
        qWarning("Couldn't list cached users: %s",
                 error.errorString(error.type()).toUtf8().constData());
        return list;
    }

    QList<QDBusObjectPath> value = reply.argumentAt<0>();
    for (int i = 0; i < value.size(); i++)
        list.append(new UserAccount(value.at(i).path(), d->interface->connection()));

    return list;
}

/*!
    Finds a user by \a uid.

    \param uid The uid to look up.
    \return the corresponding UserAccount object.
*/
UserAccount *AccountsManager::findUserById(uid_t uid)
{
    Q_D(AccountsManager);

    QDBusPendingReply<QDBusObjectPath> reply = d->interface->FindUserById(uid);
    reply.waitForFinished();

    if (reply.isError()) {
        QDBusError error = reply.error();
        qWarning("Couldn't find user by uid %d: %s", uid,
                 error.errorString(error.type()).toUtf8().constData());
        return 0;
    }

    QDBusObjectPath path = reply.argumentAt<0>();
    if (path.path().isEmpty())
        return Q_NULLPTR;
    return new UserAccount(path.path(), d->interface->connection());
}

/*!
    Finds a user by user \a userName

    \param uid The user name to look up.
    \return the corresponding UserAccount object.
*/
UserAccount *AccountsManager::findUserByName(const QString &userName)
{
    Q_D(AccountsManager);

    QDBusPendingReply<QDBusObjectPath> reply = d->interface->FindUserByName(userName);
    reply.waitForFinished();

    if (reply.isError()) {
        QDBusError error = reply.error();
        qWarning("Couldn't find user by user name %s: %s",
                 userName.toUtf8().constData(),
                 error.errorString(error.type()).toUtf8().constData());
        return 0;
    }

    QDBusObjectPath path = reply.argumentAt<0>();
    if (path.path().isEmpty())
        return Q_NULLPTR;
    return new UserAccount(path.path(), d->interface->connection());
}

/*!
    Creates a new \a accountType type user account whose name is \a userName,
    real name is \a fullName.

    \param userName The name of the new user to be created.
    \param fullName First name and last name.
    \param accountType The account type.
    \return whether the user was created successfully.
*/
bool AccountsManager::createUser(const QString &userName,
                                 const QString &fullName,
                                 UserAccount::AccountType accountType)
{
    Q_D(AccountsManager);

    QDBusPendingReply<QDBusObjectPath> reply = d->interface->CreateUser(userName, fullName, accountType);
    if (reply.isError()) {
        QDBusError error = reply.error();
        qWarning("Couldn't create user %s: %s", userName.toUtf8().constData(),
                 error.errorString(error.type()).toUtf8().constData());
        return false;
    }

    return true;
}

/*!
    Deletes the user designated by \a uid.

    \param uid The user identifier.
    \param removeFiles If true all files owned by the user will be removed.
    \return whether the user was deleted successfully.
*/
bool AccountsManager::deleteUser(uid_t uid, bool removeFiles)
{
    Q_D(AccountsManager);

    QDBusPendingReply<> reply = d->interface->DeleteUser(uid, removeFiles);
    if (reply.isError()) {
        QDBusError error = reply.error();
        qWarning("Couldn't delete user %d: %s", uid,
                 error.errorString(error.type()).toUtf8().constData());
        return false;
    }

    return true;
}

/*!
    Deletes the specified \a account.

    \param account The account to remove.
    \param removeFiles If true all files owned by the user will be removed.
    \return whether the user was deleted successfully.
*/
bool AccountsManager::deleteUser(UserAccount *account, bool removeFiles)
{
    return deleteUser(account->userId(), removeFiles);
}

}

#include "moc_accountsmanager.cpp"
