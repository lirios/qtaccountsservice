import qbs 1.0

LiriQmlPlugin {
    name: "qtaccountsserviceplugin"
    pluginPath: "QtAccountsService"

    Depends { name: "Qt6AccountsService" }

    files: ["*.cpp", "qmldir", "*.qmltypes"]
}
