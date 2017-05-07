import qbs 1.0

LiriDynamicLibrary {
    name: "qtaccountsserviceplugin"
    targetName: "qtaccountsserviceplugin"

    Depends { name: "lirideployment" }
    Depends { name: "Qt"; submodules: ["qml", "quick"] }
    Depends { name: "Qt5AccountsService" }

    files: ["*.cpp"]

    Group {
        name: "QML Files"
        files: [
            "qmldir",
            "plugins.qmltypes"
        ]
        fileTags: ["qml"]
    }

    Group {
        qbs.install: true
        qbs.installDir: lirideployment.qmlDir + "/QtAccountsService"
        fileTagsFilter: ["dynamiclibrary", "qml"]
    }
}
