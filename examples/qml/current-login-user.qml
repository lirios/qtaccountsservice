/****************************************************************************
 * This file is part of Qt AccountsService Addon.
 *
 * Copyright (C) 2015-2016 Leslie Zhai
 *
 * Author(s):
 *    Leslie Zhai <xiang.zhai@i-soft.com.cn>
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

import QtQuick 2.2
import QtQuick.Window 2.1
import QtAccountsService 1.0

Window {
    width: 300; height: 200
    title: "AccountsService Qt binding"

    UserAccount {
        id: userAccount
        Component.onCompleted: {
            faceIcon.source = iconFileName;
            loginName.text = userName;
            displayName.text = userAccount.displayName;
        }
    }

    Image {
        id: faceIcon
    }

    Text {
        id: loginName
        anchors.left: faceIcon.right
    }

    Text {
        id: displayName
        anchors.top: loginName.bottom
        anchors.left: loginName.left
    }
}
