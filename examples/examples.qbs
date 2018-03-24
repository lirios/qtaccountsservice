import qbs 1.0

Project {
    name: "Examples"

    references: [
        "listusers/listusers.qbs",
        "loggedinuser/loggedinuser.qbs",
        "useraccount/useraccount.qbs",
        "userslistview/userslistview.qbs",
    ]
}
