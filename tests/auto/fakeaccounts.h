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

#ifndef FAKEACCOUNTS_H
#define FAKEACCOUNTS_H

#include <QtCore/QObject>

#include "fakeuser.h"

class FakeAccounts : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString DaemonVersion READ daemonVersion CONSTANT)
public:
    FakeAccounts(QObject *parent = 0);
    ~FakeAccounts();

    QString daemonVersion() const;

public Q_SLOTS:
    QDBusObjectPath CacheUser(const QString &name);
    void UncacheUser(const QString &name);
    QList<QDBusObjectPath> ListCachedUsers();

    QDBusObjectPath CreateUser(const QString &name,
                               const QString &fullName,
                               int accountType);
    void DeleteUser(qlonglong id, bool removeFiles);

    QDBusObjectPath FindUserById(qlonglong id);
    QDBusObjectPath FindUserByName(const QString &name);

Q_SIGNALS:
    void UserAdded(const QDBusObjectPath &user);
    void UserDeleted(const QDBusObjectPath &user);

private:
    qlonglong m_lastUid;
    QList<FakeUser *> m_users;
};

#endif // FAKEACCOUNTS_H
