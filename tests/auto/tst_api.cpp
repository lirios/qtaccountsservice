/****************************************************************************
 * This file is part of Qt AccountsService Addon.
 *
 * Copyright (C) 2015-2016 Pier Luigi Fiorini
 *
 * Author(s):
 *    Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
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
#include "useraccount.h"

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
        // Find a user that doesn't exist
        QVERIFY(manager->findUserById(1000) == Q_NULLPTR);

        // Create user
        bool ret = manager->createUser(QStringLiteral("testuser"),
                                       QStringLiteral("Test User"),
                                       UserAccount::StandardAccountType);
        QVERIFY(ret == true);

        // Find the same user
        UserAccount *account = manager->findUserById(1000);
        QVERIFY(account != Q_NULLPTR);
        if (account)
            QCOMPARE(account->userName(), QStringLiteral("testuser"));
    }

    void cacheAccounts()
    {
        UserAccountList cachedUsers;

        // We start with no cached users
        cachedUsers = manager->listCachedUsers();
        QCOMPARE(cachedUsers.size(), 0);

        // Cache one user
        QSignalSpy spyCacheUser(manager, SIGNAL(userCached(UserAccount*)));
        manager->cacheUser(QStringLiteral("testuser"));
        QVERIFY(spyCacheUser.wait(1000));
        QCOMPARE(spyCacheUser.count(), 1);
        UserAccount *account = qvariant_cast<UserAccount *>(spyCacheUser.at(0).at(0));
        QVERIFY(account != Q_NULLPTR);
        if (account)
            QCOMPARE(account->userName(), QStringLiteral("testuser"));

        // Verify we have 1 cached user
        cachedUsers = manager->listCachedUsers();
        QCOMPARE(cachedUsers.size(), 1);

        // Uncache the user
        manager->uncacheUser(QStringLiteral("testuser"));

        // No cached users
        cachedUsers = manager->listCachedUsers();
        QCOMPARE(cachedUsers.size(), 0);
    }

    void deleteAccounts()
    {
        bool ret = manager->deleteUser(1000, false);
        QVERIFY(ret == true);
    }

private:
    FakeAccounts *accounts;
    AccountsManager *manager;
};

QTEST_MAIN(TestApi)

#include "tst_api.moc"
