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

#ifndef QTACCOUNTSSERVICE_USERACCOUNT_H
#define QTACCOUNTSSERVICE_USERACCOUNT_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtDBus/QDBusConnection>

#include <qtaccountsservice/qtaccountsservice_export.h>

namespace QtAccountsService {

class AccountsManager;
class AccountsManagerPrivate;
class UserAccountPrivate;

class QTACCOUNTSSERVICE_EXPORT UserAccount : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int uid READ userId CONSTANT)
    Q_PROPERTY(int gid READ groupId CONSTANT)
    Q_PROPERTY(AccountType accountType READ accountType WRITE setAccountType NOTIFY accountTypeChanged)
    Q_PROPERTY(bool locked READ isLocked WRITE setLocked NOTIFY lockedChanged)
    Q_PROPERTY(bool automaticLogin READ automaticLogin WRITE setAutomaticLogin NOTIFY automaticLoginChanged)
    Q_PROPERTY(qlonglong loginFrequency READ loginFrequency)
    Q_PROPERTY(qlonglong loginTime READ loginTime)
    Q_PROPERTY(PasswordMode passwordMode READ passwordMode WRITE setPasswordMode NOTIFY passwordModeChanged)
    Q_PROPERTY(QString passwordHint READ passwordHint)
    Q_PROPERTY(bool localAccount READ isLocalAccount)
    Q_PROPERTY(bool systemAccount READ isSystemAccount)
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    Q_PROPERTY(QString realName READ realName WRITE setRealName NOTIFY realNameChanged)
    Q_PROPERTY(QString displayName READ displayName NOTIFY displayNameChanged)
    Q_PROPERTY(QString homeDirectory READ homeDirectory WRITE setHomeDirectory NOTIFY homeDirectoryChanged)
    Q_PROPERTY(QString shell READ shell WRITE setShell NOTIFY shellChanged)
    Q_PROPERTY(QString iconFileName READ iconFileName WRITE setIconFileName NOTIFY iconFileNameChanged)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(QString language READ language WRITE setLanguage NOTIFY languageChanged)
    Q_PROPERTY(QString location READ location WRITE setLocation NOTIFY locationChanged)
    Q_PROPERTY(QString xsession READ xsession WRITE setXSession NOTIFY xsessionChanged)
public:
    enum AccountType {
        StandardAccountType = 0,
        AdministratorAccountType
    };
    Q_ENUM(AccountType)

    enum PasswordMode {
        RegularPasswordMode = 0,
        SetAtLoginPasswordMode,
        NonePasswordMode
    };
    Q_ENUM(PasswordMode)

    UserAccount(const QDBusConnection &bus = QDBusConnection::systemBus());
    explicit UserAccount(uid_t uid,
                         const QDBusConnection &bus = QDBusConnection::systemBus());
    ~UserAccount();

    uid_t userId() const;
    gid_t groupId() const;

    AccountType accountType() const;
    void setAccountType(AccountType type);

    bool isLocked() const;
    void setLocked(bool locked);

    bool automaticLogin() const;
    void setAutomaticLogin(bool automaticLogin);

    qlonglong loginFrequency() const;

    qlonglong loginTime() const;

    PasswordMode passwordMode() const;
    void setPasswordMode(PasswordMode mode);

    QString passwordHint() const;

    bool isLocalAccount() const;

    bool isSystemAccount() const;

    QString userName() const;
    void setUserName(const QString &userName);

    QString realName() const;
    void setRealName(const QString &realName);

    QString displayName() const;

    QString homeDirectory() const;
    void setHomeDirectory(const QString &homeDirectory);

    QString shell() const;
    void setShell(const QString &shell);

    QString iconFileName() const;
    void setIconFileName(const QString &fileName);

    QString email() const;
    void setEmail(const QString &email);

    QString language() const;
    void setLanguage(const QString &language);

    QString location() const;
    void setLocation(const QString &location);

    QString xsession() const;
    void setXSession(const QString &session);

    void setPassword(const QString &password, const QString &hint = QString());

Q_SIGNALS:
    void accountChanged();
    void accountTypeChanged();
    void lockedChanged();
    void automaticLoginChanged();
    void passwordModeChanged();
    void userNameChanged();
    void realNameChanged();
    void displayNameChanged();
    void homeDirectoryChanged();
    void shellChanged();
    void iconFileNameChanged();
    void emailChanged();
    void languageChanged();
    void locationChanged();
    void xsessionChanged();

protected:
    UserAccountPrivate *d_ptr;

private:
    friend class AccountsManager;
    friend class AccountsManagerPrivate;

    Q_DECLARE_PRIVATE(UserAccount)

    UserAccount(const QString &objectPath,
                const QDBusConnection &bus = QDBusConnection::systemBus());
};

typedef QList<UserAccount *> UserAccountList;

}

#endif // QTACCOUNTSSERVICE_USERACCOUNT_H
