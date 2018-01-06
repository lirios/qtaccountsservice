/****************************************************************************
 * This file is part of Qt AccountsService.
 *
 * Copyright (C) 2018 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 * Copyright (C) 2015-2016 Leslie Zhai <xiang.zhai@i-soft.com.cn>
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

import QtQuick 2.2
import QtQuick.Window 2.1
import QtAccountsService 1.0

Window {
    width: 300
    height: 200
    title: "QtAccountsService"
    visible: true

    UserAccount {
        id: userAccount
    }

    Image {
        id: faceIcon
        source: userAccount.iconFileName ? "file://" + userAccount.iconFileName : ""
    }

    Text {
        id: loginName
        anchors.left: faceIcon.right
        text: userAccount.userName
    }

    Text {
        id: displayName
        anchors.top: loginName.bottom
        anchors.left: loginName.left
        text: userAccount.displayName
    }
}
