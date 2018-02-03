import qbs 1.0
import qbs.FileInfo

Project {
    name: "Autotests"

    references: [
        "api/api.qbs"
    ]

    AutotestRunner {
        Depends { name: "lirideployment" }

        builtByDefault: project.autotestEnabled
        name: "qtaccountsservice-autotest"
        arguments: project.autotestArguments
        wrapper: project.autotestWrapper
        environment: {
            var env = base;
            env.push("LD_LIBRARY_PATH=" + FileInfo.joinPaths(qbs.installRoot, qbs.installPrefix, lirideployment.libDir));
            return env;
        }
    }
}
