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

#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusError>

#include "fakeuser.h"

FakeUser::FakeUser(const QString &path, qlonglong uid, const QString &name,
                   const QString &fullName, int accountType, QObject *parent)
    : QObject(parent)
    , cached(false)
    , m_uid(uid)
    , m_name(name)
    , m_fullName(fullName)
    , m_accountType(accountType)
    , m_path(QDBusObjectPath(path))
{
    QDBusConnection bus = QDBusConnection::sessionBus();

    if (!bus.registerObject(path, this))
        qFatal("Unable to register object: %s", qPrintable(bus.lastError().message()));
}

int FakeUser::accountType() const
{
    return m_accountType;
}

bool FakeUser::automaticLogin() const
{
    return false;
}

QString FakeUser::email() const
{
    return QString();
}

QString FakeUser::homeDirectory() const
{
    return QString();
}

QString FakeUser::iconFile() const
{
    return QString();
}

QString FakeUser::language() const
{
    return QString();
}

bool FakeUser::localAccount() const
{
    return false;
}

QString FakeUser::location() const
{
    return QString();
}

bool FakeUser::locked() const
{
    return false;
}

qulonglong FakeUser::loginFrequency() const
{
    return 0;
}

qlonglong FakeUser::loginTime() const
{
    return 0;
}

QString FakeUser::passwordHint() const
{
    return QString();
}

int FakeUser::passwordMode() const
{
    return 0;
}

QString FakeUser::realName() const
{
    return m_fullName;
}

QString FakeUser::shell() const
{
    return QString();
}

bool FakeUser::systemAccount() const
{
    return false;
}

qulonglong FakeUser::uid() const
{
    return m_uid;
}

QString FakeUser::userName() const
{
    return m_name;
}

QString FakeUser::xSession() const
{
    return QString();
}

QDBusObjectPath FakeUser::path() const
{
    return m_path;
}

void FakeUser::SetAccountType(int accountType)
{
    if (m_accountType == accountType)
        return;

    m_accountType = accountType;
    Q_EMIT Changed();
}

void FakeUser::SetAutomaticLogin(bool enabled)
{
    Q_UNUSED(enabled);
}

void FakeUser::SetEmail(const QString &email)
{
    Q_UNUSED(email);
}

void FakeUser::SetHomeDirectory(const QString &homedir)
{
    Q_UNUSED(homedir);
}

void FakeUser::SetIconFile(const QString &filename)
{
    Q_UNUSED(filename);
}

void FakeUser::SetLanguage(const QString &language)
{
    Q_UNUSED(language);
}

void FakeUser::SetLocation(const QString &location)
{
    Q_UNUSED(location);
}

void FakeUser::SetLocked(bool locked)
{
    Q_UNUSED(locked);
}

void FakeUser::SetPassword(const QString &password, const QString &hint)
{
    Q_UNUSED(password);
    Q_UNUSED(hint);
}

void FakeUser::SetPasswordMode(int mode)
{
    Q_UNUSED(mode);
}

void FakeUser::SetRealName(const QString &name)
{
    if (m_fullName == name)
        return;

    m_fullName = name;
    Q_EMIT Changed();
}

void FakeUser::SetShell(const QString &shell)
{
    Q_UNUSED(shell);
}

void FakeUser::SetUserName(const QString &name)
{
    if (m_name == name)
        return;

    m_name = name;
    Q_EMIT Changed();
}

void FakeUser::SetXSession(const QString &x_session)
{
    Q_UNUSED(x_session);
}

#include "moc_fakeuser.cpp"
