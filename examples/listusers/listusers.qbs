import qbs 1.0

QtApplication {
    name: "listusers"

    Depends { name: "Qt6AccountsService" }

    files: ["main.cpp"]
}
