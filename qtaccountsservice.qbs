import qbs 1.0

Project {
    name: "QtAccountsService"

    readonly property string version: "1.0.0"

    property bool withExamples: false

    property bool autotestEnabled: false
    property stringList autotestArguments: []
    property stringList autotestWrapper: []

    minimumQbsVersion: "1.6"

    qbsSearchPaths: ["qbs/shared"]

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
        builtByDefault: autotestEnabled
        name: "qtaccountsservice-autotest"
        arguments: project.autotestArguments
        wrapper: project.autotestWrapper
    }

    InstallPackage {
        name: "qtaccountsservice-artifacts"
        targetName: name
        builtByDefault: false

        archiver.type: "tar"
        archiver.outputDirectory: project.buildDirectory

        Depends { name: "Qt5AccountsService" }
        Depends { name: "QtAccountsService" }
        Depends { productTypes: ["installable"] }
    }
}
