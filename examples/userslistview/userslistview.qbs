import qbs 1.0

QtGuiApplication {
    name: "userslistview"

    Depends { name: "Qt"; submodules: ["gui", "qml"] }

    files: [
        "main.cpp",
        "resources.qrc"
    ]
}
