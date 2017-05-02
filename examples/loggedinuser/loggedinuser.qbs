import qbs 1.0

QtGuiApplication {
    name: "loggedinuser"

    Depends { name: "Qt"; submodules: ["gui", "qml"] }

    files: [
        "main.cpp",
        "resources.qrc"
    ]
}
