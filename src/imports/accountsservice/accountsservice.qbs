import qbs 1.0

LiriDynamicLibrary {
    name: "qtaccountsserviceplugin"
    targetName: "qtaccountsserviceplugin"

    Depends { name: "Qt"; submodules: ["qml", "quick"] }
    Depends { name: "libQtAccountsService" }

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
        qbs.installDir: "qml/QtAccountsService"
        fileTagsFilter: ["dynamiclibrary", "qml"]
    }
}
