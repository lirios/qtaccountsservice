import qbs 1.0

QtApplication {
    name: "listusers"

    Depends { name: "libQtAccountsService" }

    files: ["main.cpp"]
}
