import qbs 1.0
import LiriUtils

LiriModuleProject {
    id: root

    name: "Qt6AccountsService"
    moduleName: "Qt6AccountsService"
    description: "Qt-style wrapper for Accounts Service"

    resolvedProperties: ({
        Depends: [{ name: LiriUtils.quote("Qt.core") }, { name: LiriUtils.quote("Qt.dbus") },
                  { name: LiriUtils.quote("Qt.gui") }],
    })

    pkgConfigDependencies: ["Qt6Core", "Qt6DBus", "Qt6Gui"]

    cmakeDependencies: ({ "Qt6Core": project.minimumQtVersion, "Qt6DBus": project.minimumQtVersion, "Qt6Gui": project.minimumQtVersion })
    cmakeLinkLibraries: ["Qt6::Core", "Qt6::DBus", "Qt6::Gui"]

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
