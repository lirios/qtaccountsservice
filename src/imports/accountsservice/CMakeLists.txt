ecm_add_qml_module(QtAccountsServiceQmlModule
    URI
        "QtAccountsService"
    VERSION
        "2.0"
    GENERATE_PLUGIN_SOURCE
)

target_link_libraries(QtGSettingsQmlModule
    PUBLIC
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
        Qt6::Quick
        Liri::Qt6AccountsService
)

ecm_finalize_qml_module(QtAccountsServiceQmlModule)
