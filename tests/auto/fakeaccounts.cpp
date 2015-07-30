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

#include <QtCore/QDebug>
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusError>

#include "fakeaccounts.h"

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
    qDebug() << "Cache user" << name;

    Q_FOREACH (UserEntry *entry, m_users) {
        if (entry->name == name) {
            entry->cached = true;
            return entry->path;
        }
    }

    return QDBusObjectPath();
}

void FakeAccounts::UncacheUser(const QString &name)
{
    qDebug() << "Uncache user" << name;

    Q_FOREACH (UserEntry *entry, m_users) {
        if (entry->name == name) {
            entry->cached = false;
            return;
        }
    }
}

QList<QDBusObjectPath> FakeAccounts::ListCachedUsers()
{
    qDebug() << "List cached users";

    QList<QDBusObjectPath> paths;

    Q_FOREACH (UserEntry *entry, m_users) {
        if (entry->cached)
            paths.append(entry->path);
    }

    return paths;
}

QDBusObjectPath FakeAccounts::CreateUser(const QString &name,
                                         const QString &fullName,
                                         int accountType)
{
    qDebug() << "Create user" << name;

    const QString path = QString("/org/freedesktop/Accounts/User%1").arg(m_lastUid);
    UserEntry *entry = new UserEntry;
    entry->uid = m_lastUid;
    entry->name = name;
    entry->fullName = fullName;
    entry->accountType = accountType;
    entry->path = QDBusObjectPath(path);
    entry->cached = false;
    m_users.append(entry),
    m_lastUid++;
    return entry->path;
}

void FakeAccounts::DeleteUser(qlonglong id, bool removeFiles)
{
    qDebug() << "Delete user" << id;

    Q_UNUSED(removeFiles);

    Q_FOREACH (UserEntry *entry, m_users) {
        if (entry->uid == id) {
            m_users.removeOne(entry);
            delete entry;
            return;
        }
    }
}

QDBusObjectPath FakeAccounts::FindUserById(qlonglong id)
{
    qDebug() << "Find user by id" << id;

    Q_FOREACH (UserEntry *entry, m_users) {
        if (entry->uid == id)
            return entry->path;
    }

    return QDBusObjectPath();
}

QDBusObjectPath FakeAccounts::FindUserByName(const QString &name)
{
    qDebug() << "Find user by name" << name;

    Q_FOREACH (UserEntry *entry, m_users) {
        if (entry->name == name)
            return entry->path;
    }

    return QDBusObjectPath();
}

#include "moc_fakeaccounts.cpp"
