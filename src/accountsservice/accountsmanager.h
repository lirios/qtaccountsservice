/****************************************************************************
 * This file is part of Qt AccountsService.
 *
 * Copyright (C) 2017 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * $BEGIN_LICENSE:LGPLv3+$
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#ifndef QTACCOUNTSSERVICE_ACCOUNTSMANAGER_H
#define QTACCOUNTSSERVICE_ACCOUNTSMANAGER_H

#include <QtCore/QObject>
#include <QtDBus/QDBusConnection>

#include <Qt5AccountsService/UserAccount>

QT_FORWARD_DECLARE_CLASS(QDBusObjectPath)

namespace QtAccountsService {

class AccountsManagerPrivate;

class Q_ACCOUNTS_SERVICE_EXPORT AccountsManager : public QObject
{
    Q_OBJECT
public:
    explicit AccountsManager(const QDBusConnection &bus = QDBusConnection::systemBus(),
                             QObject *parent = nullptr);
    ~AccountsManager();

    void cacheUser(const QString &userName);
    void uncacheUser(const QString &userName);

    void listCachedUsers();
    UserAccountList listCachedUsersSync();

    UserAccount *cachedUser(const QString &userName) const;

    UserAccount *findUserById(uid_t uid);
    UserAccount *findUserByName(const QString &userName);

    bool createUser(const QString &userName,
                    const QString &fullName,
                    UserAccount::AccountType accountType);

    bool deleteUser(uid_t uid, bool removeFiles);
    bool deleteUser(UserAccount *account, bool removeFiles);

Q_SIGNALS:
    void userAdded(UserAccount *);
    void userDeleted(quint32 uid);
    void userCached(const QString &userName);
    void userUncached(const QString &userName);
    void listCachedUsersFinished(const UserAccountList &userList);

protected:
    AccountsManagerPrivate *d_ptr;

private:
    Q_DECLARE_PRIVATE(AccountsManager)
    Q_PRIVATE_SLOT(d_func(), void _q_userAdded(const QDBusObjectPath &path))
    Q_PRIVATE_SLOT(d_func(), void _q_userDeleted(const QDBusObjectPath &path))
};

}

#endif // QTACCOUNTSSERVICE_ACCOUNTSMANAGER_H
