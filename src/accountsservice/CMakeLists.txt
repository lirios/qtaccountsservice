qt6_add_dbus_interfaces(
    SOURCES
    org.freedesktop.Accounts.xml
    org.freedesktop.Accounts.User.xml
)

liri_add_module(Qt6AccountsService
    DESCRIPTION
        "Qt style API for Accounts Service"
    MODULE_NAME
        Qt6AccountsService
    VERSIONED_MODULE_NAME
        Qt6AccountsService
    SOURCES
        accountsmanager.cpp accountsmanager.h accountsmanager_p.h
        useraccount.cpp useraccount.h useraccount_p.h
        usersmodel.cpp usersmodel.h usersmodel_p.h
        ${SOURCES}
    PUBLIC_LIBRARIES
        Qt6::Core
        Qt6::DBus
        Qt6::Gui
        Qt6::QmlIntegration
    PKGCONFIG_DEPENDENCIES
        Qt6Core
        Qt6DBus
        Qt6Gui
        Qt6QmlIntegration
)

liri_finalize_module(Qt6AccountsService)

if(TARGET Qt6::Qml)
    ecm_add_qml_module(Qt6AccountsService
        URI QtAccountsService
        VERSION 2.0
        GENERATE_PLUGIN_SOURCE
    )

    ecm_finalize_qml_module(Qt6AccountsService)
endif()
