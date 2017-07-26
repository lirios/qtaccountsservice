import qbs 1.0
import LiriUtils

LiriModuleProject {
    id: root

    name: "Qt5AccountsService"
    moduleName: "Qt5AccountsService"
    description: "Qt-style wrapper for Accounts Service"

    resolvedProperties: ({
        Depends: [{ name: LiriUtils.quote("Qt.core") }, { name: LiriUtils.quote("Qt.dbus") },
                  { name: LiriUtils.quote("Qt.gui") }],
    })

    pkgConfigDependencies: ["Qt5Core", "Qt5DBus", "Qt5Gui"]

    cmakeDependencies: ({ "Qt5Core": "5.8", "Qt5DBus": "5.8", "Qt5Gui": "5.8" })
    cmakeLinkLibraries: ["Qt5::Core", "Qt5::DBus", "Qt5::Gui"]

    LiriHeaders {
        name: root.headersName
        sync.module: root.moduleName

        Group {
            name: "Headers"
            files: "**/*.h"
            fileTags: ["hpp_syncable"]
        }
    }

    LiriModule {
        name: root.moduleName
        targetName: root.targetName
        version: "1.0.0"

        Depends { name: root.headersName }
        Depends { name: "Qt"; submodules: ["core", "dbus", "gui"] }

        cpp.defines: base.concat([
            "QTACCOUNTSSERVICE_VERSION=" + project.version,
            "QT_BUILD_QTACCOUNTSSERVICE_LIB"
        ])

        files: ["*.cpp", "*.h"]

        Group {
            name: "D-Bus Interfaces"
            files: [
                "org.freedesktop.Accounts.xml",
                "org.freedesktop.Accounts.User.xml"
            ]
            fileTags: ["qt.dbus.interface"]
        }

        Export {
            Depends { name: "cpp" }
            Depends { name: root.headersName }
            Depends { name: "Qt"; submodules: ["core", "dbus", "gui"] }
        }
    }
}
