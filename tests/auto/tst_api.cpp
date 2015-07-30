/****************************************************************************
 * This file is part of Qt AccountsService Addon.
 *
 * Copyright (C) 2015 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * Author(s):
 *    Pier Luigi Fiorini
 *
 * $BEGIN_LICENSE:GPL2+$
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $END_LICENSE$
 ***************************************************************************/

#include <QtTest/QtTest>

#include "fakeaccounts.h"
#include "fakeaccountsadaptor.h"
#include "accountsmanager.h"

using namespace QtAccountsService;

class TestApi : public QObject
{
    Q_OBJECT
public:
    TestApi(QObject *parent = 0)
        : QObject(parent)
        , accounts(Q_NULLPTR)
        , manager(Q_NULLPTR)
    {
    }

private Q_SLOTS:
    void initTestCase()
    {
        accounts = new FakeAccounts(this);
        new FakeAccountsAdaptor(accounts);
        manager = new AccountsManager(QDBusConnection::sessionBus());
    }

    void cleanupTestCase()
    {
        delete manager;
        manager = Q_NULLPTR;

        delete accounts;
        accounts = Q_NULLPTR;
    }

    void createAccounts()
    {
        bool ret = manager->createUser(QStringLiteral("testuser"),
                                       QStringLiteral("Test User"),
                                       UserAccount::StandardAccountType);
        QVERIFY(ret == true);
    }

    void deleteAccounts()
    {
        bool ret;
        ret = manager->deleteUser(1000, false);
        QVERIFY(ret == true);
        ret = manager->deleteUser(1000, false);
        QVERIFY(ret == false);
    }

private:
    FakeAccounts *accounts;
    AccountsManager *manager;
};

QTEST_MAIN(TestApi)

#include "tst_api.moc"
