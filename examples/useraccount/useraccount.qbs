import qbs 1.0

QtGuiApplication {
    name: "useraccount"

    Depends { name: "Qt"; submodules: ["gui", "qml"]; versionAtLeast: project.minimumQtVersion }

    files: [
        "main.cpp",
        "resources.qrc"
    ]
}
