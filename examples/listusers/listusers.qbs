import qbs 1.0

QtApplication {
    name: "listusers"

    Depends { name: "Qt5AccountsService" }

    files: ["main.cpp"]
}
