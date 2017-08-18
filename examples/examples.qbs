import qbs 1.0

Project {
    name: "Examples"

    references: [
        "examples/listusers/listusers.qbs",
        "examples/loggedinuser/loggedinuser.qbs",
        "examples/useraccount/useraccount.qbs",
        "examples/userslistview/userslistview.qbs",
    ]
}
