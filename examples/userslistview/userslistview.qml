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

import QtQuick 2.0
import QtQuick.Window 2.0
import QtAccountsService 1.0

Window {
    width: 600
    height: 400
    title: "QtAccountsService"
    visible: true

    ListView {
        anchors.fill: parent

        model: UsersModel {}
        spacing: 8
        delegate: Row {
            spacing: 8

            Image {
                width: 96
                height: width
                source: iconFileName ? "file://" + iconFileName : ""
            }

            Text {
                text: "User name: " + userName + "\n" + "Real name: " + realName
            }
        }
    }
}
