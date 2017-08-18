import qbs 1.0

Project {
    name: "Autotests"

    references: [
        "api/api.qbs"
    ]

    AutotestRunner {
        builtByDefault: project.autotestEnabled
        name: "qtaccountsservice-autotest"
        arguments: project.autotestArguments
        wrapper: project.autotestWrapper
    }
}
