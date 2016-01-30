/****************************************************************************
 * This file is part of Qt AccountsService Addon.
 *
 * Copyright (C) 2012-2016 Pier Luigi Fiorini
 *
 * Author(s):
 *    Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
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

#ifndef QTACCOUNTSSERVICE_USERSMODEL_P_H
#define QTACCOUNTSSERVICE_USERSMODEL_P_H

#include <QtAccountsService/AccountsManager>
#include <QtAccountsService/UserAccount>

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt AccountsService Addon API.  It exists
// purely as an implementation detail.  This header file may change from
// version to version without notice, or even be removed.
//
// We mean it.
//

namespace QtAccountsService {

class UsersModel;

class UsersModelPrivate
{
    Q_DECLARE_PUBLIC(UsersModel)
public:
    UsersModelPrivate();
    ~UsersModelPrivate();

    void populate();

    UsersModel *q_ptr;
    AccountsManager *manager;
    UserAccountList list;

public Q_SLOTS:
    void _q_userAdded(UserAccount *account);
    void _q_userDeleted(UserAccount *account);
};

}

#endif // QTACCOUNTSSERVICE_USERSMODEL_P_H
