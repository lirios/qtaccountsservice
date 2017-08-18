import qbs 1.0

Project {
    name: "Deployment"

    InstallPackage {
        name: "qtaccountsservice-artifacts"
        targetName: name
        builtByDefault: false

        archiver.type: "tar"
        archiver.outputDirectory: project.buildDirectory

        Depends { name: "Qt5AccountsService" }
        Depends { name: "Qt5AccountsService-cmake" }
        Depends { name: "Qt5AccountsService-pkgconfig" }
        Depends { name: "Qt5AccountsService-qbs" }
        Depends { name: "qtaccountsserviceplugin" }
        Depends { productTypes: ["installable"] }
    }
}
