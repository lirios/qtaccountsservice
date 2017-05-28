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

#include <QtTest/QtTest>

#include <Qt5AccountsService/AccountsManager>
#include <Qt5AccountsService/UserAccount>

#include "fakeaccounts.h"
#include "accounts_adaptor.h"

using namespace QtAccountsService;

class TestApi : public QObject
{
    Q_OBJECT
public:
    TestApi(QObject *parent = nullptr)
        : QObject(parent)
        , accounts(nullptr)
        , manager(nullptr)
    {
    }

private Q_SLOTS:
    void initTestCase()
    {
        accounts = new FakeAccounts(this);
        new AccountsAdaptor(accounts);
        manager = new AccountsManager(QDBusConnection::sessionBus());
    }

    void cleanupTestCase()
    {
        delete manager;
        manager = nullptr;

        delete accounts;
        accounts = nullptr;
    }

    void createAccounts()
    {
        // Find a user that doesn't exist
        QVERIFY(manager->findUserById(1000) == nullptr);

        // Create user
        bool ret = manager->createUser(QStringLiteral("testuser"),
                                       QStringLiteral("Test User"),
                                       UserAccount::StandardAccountType);
        QVERIFY(ret == true);

        // Find the same user
        UserAccount *account = manager->findUserById(1000);
        QVERIFY(account != nullptr);
        if (account)
            QCOMPARE(account->userName(), QStringLiteral("testuser"));
    }

    void cacheAccounts()
    {
        UserAccountList cachedUsers;

        // We start with no cached users
        cachedUsers = manager->listCachedUsersSync();
        QCOMPARE(cachedUsers.size(), 0);

        // Cache one user
        QSignalSpy spyCacheUser(manager, SIGNAL(userCached(QString)));
        manager->cacheUser(QStringLiteral("testuser"));
        QVERIFY(spyCacheUser.wait(1000));
        QCOMPARE(spyCacheUser.count(), 1);
        QList<QVariant> arguments = spyCacheUser.takeFirst();
        QCOMPARE(arguments.at(0).toString(), QStringLiteral("testuser"));
        UserAccount *account = manager->cachedUser(arguments.at(0).toString());
        QVERIFY(account != nullptr);
        if (account)
            QCOMPARE(account->userName(), QStringLiteral("testuser"));

        // Verify we have 1 cached user
        cachedUsers = manager->listCachedUsersSync();
        QCOMPARE(cachedUsers.size(), 1);

        // Uncache the user
        manager->uncacheUser(QStringLiteral("testuser"));

        // No cached users
        cachedUsers = manager->listCachedUsersSync();
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
