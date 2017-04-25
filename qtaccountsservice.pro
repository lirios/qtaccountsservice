defineTest(minQtVersion) {
    maj = $$1
    min = $$2
    patch = $$3
    isEqual(QT_MAJOR_VERSION, $$maj) {
        isEqual(QT_MINOR_VERSION, $$min) {
            isEqual(QT_PATCH_VERSION, $$patch) {
                return(true)
            }
            greaterThan(QT_PATCH_VERSION, $$patch) {
                return(true)
            }
        }
        greaterThan(QT_MINOR_VERSION, $$min) {
            return(true)
        }
    }
    greaterThan(QT_MAJOR_VERSION, $$maj) {
        return(true)
    }
    return(false)
}

!minQtVersion(5, 8, 0): \
    error("QtAccountsService requires at least Qt 5.8.0, but $${QT_VERSION} was detected.")

!exists(features/liri_deployment.prf): \
    error("Git submodule missing. Run \'git submodule update --init\' in $${PWD}.")

TEMPLATE = subdirs

SUBDIRS += src examples tests
CONFIG += ordered

OTHER_FILES += \
    $$PWD/AUTHORS.md \
    $$PWD/LICENSE.FDL \
    $$PWD/LICENSE.LGPLv3 \
    $$PWD/README.md
