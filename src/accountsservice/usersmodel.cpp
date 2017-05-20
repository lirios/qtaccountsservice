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

#include <QtConcurrent/QtConcurrentRun>
#include <QtGui/QPixmap>

#include "usersmodel.h"
#include "usersmodel_p.h"

namespace QtAccountsService {

/*
 * UsersModelPrivate
 */

UsersModelPrivate::UsersModelPrivate()
    : QAbstractItemModelPrivate()
{
    manager = new AccountsManager();
}

UsersModelPrivate::~UsersModelPrivate()
{
    delete manager;
}

void UsersModelPrivate::_q_userAdded(UserAccount *account)
{
    Q_Q(UsersModel);

    q->beginInsertRows(QModelIndex(), list.size(), list.size());
    list.append(account);
    q->endInsertRows();
}

void UsersModelPrivate::_q_userDeleted(uid_t uid)
{
    Q_Q(UsersModel);

    for (int i = 0; i < list.size(); i++) {
        UserAccount *curAccount = list.at(i);

        if (curAccount->userId() == uid) {
            q->beginRemoveRows(QModelIndex(), i, i);
            list.removeOne(curAccount);
            q->endRemoveRows();
            break;
        }
    }
}

/*
 * UsersModel
 */

UsersModel::UsersModel(QObject *parent)
    : QAbstractListModel(*new UsersModelPrivate(), parent)
{
    Q_D(UsersModel);

    connect(d->manager, SIGNAL(userAdded(UserAccount*)),
            this, SLOT(_q_userAdded(UserAccount*)));
    connect(d->manager, SIGNAL(userDeleted(uid_t)),
            this, SLOT(_q_userDeleted(uid_t)));

    auto func = [](UsersModelPrivate *d) {
        d->list = d->manager->listCachedUsers();
    };
    QtConcurrent::run(func, d);
}

QHash<int, QByteArray> UsersModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractItemModel::roleNames();
    roles[UserIdRole] = "userId";
    roles[UserNameRole] = "userName";
    roles[RealNameRole] = "realName";
    roles[IconFileNameRole] = "iconFileName";
    roles[AccountTypeRole] = "accountType";
    roles[LanguageRole] = "language";
    return roles;
}

int UsersModel::rowCount(const QModelIndex &parent) const
{
    Q_D(const UsersModel);

    if (parent == QModelIndex())
        return d->list.size();

    return 0;
}

QVariant UsersModel::data(const QModelIndex &index, int role) const
{
    UserAccount *user = userAccount(index);
    if (!user)
        return QVariant();

    switch (role) {
    case Qt::DisplayRole:
        return user->displayName();
    case Qt::DecorationRole:
        return QPixmap(user->iconFileName());
    case UsersModel::UserIdRole:
        return user->userId();
    case UsersModel::UserNameRole:
        return user->userName();
    case UsersModel::RealNameRole:
        return user->realName();
    case UsersModel::IconFileNameRole:
        return user->iconFileName();
    case UsersModel::AccountTypeRole:
        return user->accountType();
    case UsersModel::LanguageRole:
        return user->language();
    default:
        break;
    }

    return QVariant();
}

bool UsersModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    UserAccount *user = userAccount(index);
    if (!user)
        return false;

    switch (role) {
    case UsersModel::UserNameRole:
        user->setUserName(value.toString());
        break;
    case UsersModel::RealNameRole:
        user->setRealName(value.toString());
        break;
    case UsersModel::IconFileNameRole:
        user->setIconFileName(value.toString());
        break;
    case UsersModel::AccountTypeRole:
        user->setAccountType((UserAccount::AccountType) value.toInt());
        break;
    case UsersModel::LanguageRole:
        user->setLanguage(value.toString());
        break;
    default:
        return false;
    }

    return true;
}

UserAccount *UsersModel::userAccount(const QModelIndex &index) const
{
    Q_D(const UsersModel);

    if (!index.isValid())
        return Q_NULLPTR;
    if (index.row() >= d->list.size())
        return Q_NULLPTR;

    return d->list[index.row()];
}

}

#include "moc_usersmodel.cpp"
