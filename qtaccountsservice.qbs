import qbs 1.0

Project {
    name: "QtAccountsService"

    readonly property string version: "1.1.0"
    readonly property var versionParts: version.split('.').map(function(part) { return parseInt(part); })

    property bool withExamples: false

    property bool autotestEnabled: false
    property stringList autotestArguments: []
    property stringList autotestWrapper: []

    minimumQbsVersion: "1.8.0"

    references: [
        "src/deployment.qbs",
        "src/accountsservice/accountsservice.qbs",
        "src/imports/imports.qbs",
        "tests/auto/auto.qbs",
    ]

    SubProject {
        filePath: "examples/examples.qbs"
        Properties {
            condition: parent.withExamples
        }
    }
}
