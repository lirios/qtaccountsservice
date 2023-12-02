/****************************************************************************
 * This file is part of Qt AccountsService.
 *
 * Copyright (C) 2018 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
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

#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusError>

#include "fakeaccounts.h"
#include "useradaptor.h"

FakeAccounts::FakeAccounts(QObject *parent)
    : QObject(parent)
    , m_lastUid(1000)
{
    QDBusConnection bus = QDBusConnection::sessionBus();

    if (!bus.registerObject(QStringLiteral("/org/freedesktop/Accounts"), this))
        qFatal("Unable to register object: %s", qPrintable(bus.lastError().message()));
    if (!bus.registerService(QStringLiteral("org.freedesktop.Accounts")))
        qFatal("Unable to register service: %s", qPrintable(bus.lastError().message()));
}

FakeAccounts::~FakeAccounts()
{
    qDeleteAll(m_users);
}

QString FakeAccounts::daemonVersion() const
{
    return QStringLiteral("42");
}

QDBusObjectPath FakeAccounts::CacheUser(const QString &name)
{
    for (FakeUser *entry : qAsConst(m_users)) {
        if (entry->userName() == name) {
            entry->cached = true;
            return entry->path();
        }
    }

    return QDBusObjectPath();
}

void FakeAccounts::UncacheUser(const QString &name)
{
    for (FakeUser *entry : qAsConst(m_users)) {
        if (entry->userName() == name) {
            entry->cached = false;
            return;
        }
    }
}

QList<QDBusObjectPath> FakeAccounts::ListCachedUsers()
{
    QList<QDBusObjectPath> paths;

    for (FakeUser *entry : qAsConst(m_users)) {
        if (entry->cached)
            paths.append(entry->path());
    }

    return paths;
}

QDBusObjectPath FakeAccounts::CreateUser(const QString &name, const QString &fullName,
                                         int accountType)
{
    const QString path = QStringLiteral("/org/freedesktop/Accounts/User%1").arg(m_lastUid);
    FakeUser *entry = new FakeUser(path, m_lastUid, name, fullName, accountType, this);
    new UserAdaptor(entry);
    m_users.append(entry);
    m_lastUid++;
    return entry->path();
}

void FakeAccounts::DeleteUser(qlonglong id, bool removeFiles)
{
    Q_UNUSED(removeFiles);

    for (FakeUser *entry : qAsConst(m_users)) {
        if ((qlonglong)entry->uid() == id) {
            m_users.removeOne(entry);
            delete entry;
            return;
        }
    }
}

QDBusObjectPath FakeAccounts::FindUserById(qlonglong id)
{
    for (FakeUser *entry : qAsConst(m_users)) {
        if ((qlonglong)entry->uid() == id)
            return entry->path();
    }

    return QDBusObjectPath();
}

QDBusObjectPath FakeAccounts::FindUserByName(const QString &name)
{
    for (FakeUser *entry : qAsConst(m_users)) {
        if (entry->userName() == name)
            return entry->path();
    }

    return QDBusObjectPath();
}
