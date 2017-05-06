import qbs 1.0

LiriModule {
    name: "libQtAccountsService"

    targetName: "Qt5AccountsService"
    version: "0.0.0"

    Depends { name: "Qt"; submodules: ["core", "core-private", "dbus", "gui"] }

    cpp.defines: base.concat(["QTACCOUNTSSERVICE_VERSION=" + project.version])

    create_headers.headersMap: ({
        "accountsmanager.h": "AccountsManager",
        "useraccount.h": "UserAccount",
        "usersmodel.h": "UsersModel",
    })

    create_pkgconfig.name: "Qt Accounts Service"
    create_pkgconfig.description: "Qt-style wrapper for Accounts Service"
    create_pkgconfig.version: project.version
    create_pkgconfig.dependencies: ["Qt5Core", "Qt5DBus", "Qt5Gui"]

    create_cmake.version: project.version
    create_cmake.dependencies: ({
        "Qt5Core": "5.8",
        "Qt5DBus": "5.8",
        "Qt5Gui": "5.8"
    })
    create_cmake.linkLibraries: ["Qt5::Core", "Qt5::DBus", "Qt5::Gui"]

    files: ["*.cpp"]

    Group {
        name: "Headers"
        files: ["*.h"]
        excludeFiles: ["*_p.h"]
        fileTags: ["public_headers"]
    }

    Group {
        name: "Private Headers"
        files: ["*_p.h"]
        fileTags: ["private_headers"]
    }

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
        Depends { name: "Qt"; submodules: ["core", "core-private", "dbus", "gui"] }

        cpp.includePaths: product.generatedHeadersDir
    }
}
