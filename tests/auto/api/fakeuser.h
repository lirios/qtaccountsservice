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

#ifndef FAKEUSER_H
#define FAKEUSER_H

#include <QtCore/QObject>
#include <QtDBus/QDBusObjectPath>

class FakeUser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int AccountType READ accountType CONSTANT)
    Q_PROPERTY(bool AutomaticLogin READ automaticLogin CONSTANT)
    Q_PROPERTY(QString Email READ email CONSTANT)
    Q_PROPERTY(QString HomeDirectory READ homeDirectory CONSTANT)
    Q_PROPERTY(QString IconFile READ iconFile CONSTANT)
    Q_PROPERTY(QString Language READ language CONSTANT)
    Q_PROPERTY(bool LocalAccount READ localAccount CONSTANT)
    Q_PROPERTY(QString Location READ location CONSTANT)
    Q_PROPERTY(bool Locked READ locked CONSTANT)
    Q_PROPERTY(qulonglong LoginFrequency READ loginFrequency CONSTANT)
    Q_PROPERTY(qlonglong LoginTime READ loginTime CONSTANT)
    Q_PROPERTY(QString PasswordHint READ passwordHint CONSTANT)
    Q_PROPERTY(int PasswordMode READ passwordMode CONSTANT)
    Q_PROPERTY(QString RealName READ realName CONSTANT)
    Q_PROPERTY(QString Shell READ shell CONSTANT)
    Q_PROPERTY(bool SystemAccount READ systemAccount CONSTANT)
    Q_PROPERTY(qulonglong Uid READ uid CONSTANT)
    Q_PROPERTY(QString UserName READ userName CONSTANT)
    Q_PROPERTY(QString XSession READ xSession CONSTANT)

public:
    FakeUser(const QString &path, qlonglong uid, const QString &name, const QString &fullName,
             int accountType, QObject *parent = 0);

    int accountType() const;
    bool automaticLogin() const;
    QString email() const;
    QString homeDirectory() const;
    QString iconFile() const;
    QString language() const;
    bool localAccount() const;
    QString location() const;
    bool locked() const;
    qulonglong loginFrequency() const;
    qlonglong loginTime() const;
    QString passwordHint() const;
    int passwordMode() const;
    QString realName() const;
    QString shell() const;
    bool systemAccount() const;
    qulonglong uid() const;
    QString userName() const;
    QString xSession() const;

    QDBusObjectPath path() const;

    bool cached;

public Q_SLOTS:
    void SetAccountType(int accountType);
    void SetAutomaticLogin(bool enabled);
    void SetEmail(const QString &email);
    void SetHomeDirectory(const QString &homedir);
    void SetIconFile(const QString &filename);
    void SetLanguage(const QString &language);
    void SetLocation(const QString &location);
    void SetLocked(bool locked);
    void SetPassword(const QString &password, const QString &hint);
    void SetPasswordMode(int mode);
    void SetRealName(const QString &name);
    void SetShell(const QString &shell);
    void SetUserName(const QString &name);
    void SetXSession(const QString &x_session);

Q_SIGNALS:
    void Changed();

private:
    qulonglong m_uid;
    QString m_name;
    QString m_fullName;
    int m_accountType;
    QDBusObjectPath m_path;
};

#endif // FAKEUSER_H
