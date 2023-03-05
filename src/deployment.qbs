import qbs 1.0

Project {
    name: "Deployment"

    InstallPackage {
        name: "qtaccountsservice-artifacts"
        targetName: name
        builtByDefault: false

        archiver.type: "tar"
        archiver.outputDirectory: project.buildDirectory

        Depends { name: "Qt6AccountsService" }
        Depends { name: "Qt6AccountsService-cmake" }
        Depends { name: "Qt6AccountsService-pkgconfig" }
        Depends { name: "Qt6AccountsService-qbs" }
        Depends { name: "qtaccountsserviceplugin" }
        Depends { productTypes: ["installable"] }
    }
}
