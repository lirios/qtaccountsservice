liri_add_qml_plugin(qtaccountsservice
    MODULE_PATH
        "QtAccountsService"
    VERSION
        "1.0"
    SOURCES
        main.cpp
    QML_FILES
        qmldir
    DEFINES
        QT_NO_CAST_FROM_ASCII
        QT_NO_FOREACH
    PUBLIC_LIBRARIES
        Liri::Qt6AccountsService
)

liri_finalize_qml_plugin(qtaccountsservice)
