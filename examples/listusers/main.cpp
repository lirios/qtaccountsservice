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

#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>

#include <Qt5AccountsService/AccountsManager>
#include <Qt5AccountsService/UserAccount>

using namespace QtAccountsService;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    AccountsManager *manager = new AccountsManager();
    UserAccountList list = manager->listCachedUsers();
    Q_FOREACH (UserAccount *account, list)
        qInfo() << account->realName() << account->userName();

    return app.exec();
}
