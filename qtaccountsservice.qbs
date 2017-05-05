import qbs 1.0

Project {
    name: "QtAccountsService"

    readonly property string version: "0.7.0"

    property bool withExamples: false
    property stringList autotestArguments: []
    property stringList autotestWrapper: []

    minimumQbsVersion: "1.6"

    qbsSearchPaths: "qbs-shared"

    references: [
        "src/accountsservice/accountsservice.qbs",
        "src/imports/accountsservice/accountsservice.qbs",
        "tests/auto/auto.qbs",
    ]

    SubProject {
        filePath: "examples/examples.qbs"
        Properties {
            condition: parent.withExamples
        }
    }

    AutotestRunner {
        arguments: project.autotestArguments
        wrapper: project.autotestWrapper
    }
}
