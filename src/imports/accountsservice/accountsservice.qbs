import qbs 1.0

LiriQmlPlugin {
    name: "qtaccountsserviceplugin"
    pluginPath: "QtAccountsService"

    Depends { name: "Qt5AccountsService" }

    files: ["*.cpp", "qmldir", "*.qmltypes"]
}
