import qbs 1.0

QtApplication {
    name: "tst_api"
    type: base.concat(["autotest"])

    Depends { name: "Qt"; submodules: ["core", "dbus", "testlib"] }
    Depends { name: "libQtAccountsService" }

    files: [
        "fakeaccounts.cpp",
        "fakeaccounts.h",
        "fakeuser.cpp",
        "fakeuser.h",
        "tst_api.cpp"
    ]

    Group {
        name: "D-Bus Interfaces"
        files: [
            "../../../src/accountsservice/org.freedesktop.Accounts.xml",
            "../../../src/accountsservice/org.freedesktop.Accounts.User.xml"
        ]
        fileTags: ["qt.dbus.adaptor"]
    }
}
