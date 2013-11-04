/****************************************************************************
 * This file is part of Qt AccountsService Addon.
 *
 * Copyright (C) 2012-2013 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
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

#ifndef ACCOUNTSMANAGER_H
#define ACCOUNTSMANAGER_H

#include <QtCore/qobject.h>

#include <QtAccountsService/UserAccount>

QT_FORWARD_DECLARE_CLASS(QDBusObjectPath)

QT_BEGIN_NAMESPACE_ACCOUNTSSERVICE

class AccountsManagerPrivate;

class Q_ACCOUNTSSERVICE_EXPORT AccountsManager : public QObject
{
    Q_OBJECT
public:
    explicit AccountsManager();
    ~AccountsManager();

    UserAccount *cacheUser(const QString &userName);
    void uncacheUser(const QString &userName);
    void uncacheUser(UserAccount *account);

    UserAccountList listCachedUsers();

    UserAccount *findUserById(uid_t uid);
    UserAccount *findUserByName(const QString &userName);

    bool createUser(const QString &userName,
                    const QString &fullName,
                    UserAccount::AccountType accountType);

    bool deleteUser(uid_t uid, bool removeFiles);
    bool deleteUser(UserAccount *account, bool removeFiles);

Q_SIGNALS:
    void userAdded(UserAccount *);
    void userDeleted(UserAccount *);

protected:
    AccountsManagerPrivate *d_ptr;

private:
    Q_DECLARE_PRIVATE(AccountsManager)
    Q_PRIVATE_SLOT(d_func(), void _q_userAdded(const QDBusObjectPath &path))
    Q_PRIVATE_SLOT(d_func(), void _q_userDeleted(const QDBusObjectPath &path))
};

QT_END_NAMESPACE_ACCOUNTSSERVICE

#endif // ACCOUNTSMANAGER_H
