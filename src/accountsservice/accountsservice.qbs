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

    cmakeDependencies: ({ "Qt5Core": project.minimumQtVersion, "Qt5DBus": project.minimumQtVersion, "Qt5Gui": project.minimumQtVersion })
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
        Depends { name: "Qt"; submodules: ["core", "dbus", "gui"]; versionAtLeast: project.minimumQtVersion }

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
            Depends { name: "Qt"; submodules: ["core", "dbus", "gui"]; versionAtLeast: project.minimumQtVersion }
        }
    }
}
