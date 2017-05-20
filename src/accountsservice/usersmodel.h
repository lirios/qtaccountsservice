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

#ifndef QTACCOUNTSSERVICE_USERSMODEL_H
#define QTACCOUNTSSERVICE_USERSMODEL_H

#include <QtCore/QAbstractListModel>

#include <Qt5AccountsService/qtaccountsserviceglobal.h>

namespace QtAccountsService {

class UserAccount;
class UsersModelPrivate;

class Q_ACCOUNTS_SERVICE_EXPORT UsersModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        UserIdRole = Qt::UserRole + 1,
        UserNameRole,
        RealNameRole,
        IconFileNameRole,
        AccountTypeRole,
        LanguageRole
    };
    Q_ENUM(Roles)

    explicit UsersModel(QObject *parent = 0);

    QHash<int, QByteArray> roleNames() const;

    int rowCount(const QModelIndex &parent) const;

    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    UserAccount *userAccount(const QModelIndex &index) const;

private:
    Q_DECLARE_PRIVATE(UsersModel)
    Q_PRIVATE_SLOT(d_func(), void _q_userAdded(UserAccount *account))
    Q_PRIVATE_SLOT(d_func(), void _q_userDeleted(uid_t uid))
};

}

#endif // QTACCOUNTSSERVICE_USERSMODEL_H
