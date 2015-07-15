include(GenerateExportHeader)
include(ECMPackageConfigHelpers)
include(ECMSetupVersion)
include(ECMGenerateHeaders)

ecm_setup_version(${PROJECT_VERSION} VARIABLE_PREFIX QTACCOUNTSSERVICE
                  VERSION_HEADER "${CMAKE_CURRENT_BINARY_DIR}/qtaccountsservice_version.h"
                  PACKAGE_VERSION_FILE "${CMAKE_CURRENT_BINARY_DIR}/QtAccountsServiceConfigVersion.cmake"
                  SOVERSION ${PROJECT_SOVERSION})

include_directories(
    ${CMAKE_SOURCE_DIR}/headers
    ${CMAKE_BINARY_DIR}/headers
)

set(SOURCES
    accountsmanager.cpp
    useraccount.cpp
    usersmodel.cpp
)

set(HEADERS
    accountsmanager.h
    useraccount.h
    usersmodel.h
)

qt5_add_dbus_interface(SOURCES
                       ${CMAKE_CURRENT_SOURCE_DIR}/org.freedesktop.Accounts.User.xml
                       user_interface)
qt5_add_dbus_interface(SOURCES
                       ${CMAKE_CURRENT_SOURCE_DIR}/org.freedesktop.Accounts.xml
                       accounts_interface)

add_library(QtAccountsService SHARED ${SOURCES})
generate_export_header(QtAccountsService EXPORT_FILE_NAME qtaccountsservice/qtaccountsservice_export.h)
add_library(QtAccountsService::QtAccountsService ALIAS QtAccountsService)

target_link_libraries(QtAccountsService
                      Qt5::Core
                      Qt5::DBus
                      Qt5::Gui
)

set(QTACCOUNTSSERVICE_INCLUDEDIR "${CMAKE_INSTALL_INCLUDEDIR}/QtAccountsService")

target_include_directories(QtAccountsService INTERFACE "$<INSTALL_INTERFACE:${QTACCOUNTSSERVICE_INCLUDEDIR}>")

set_target_properties(QtAccountsService PROPERTIES
                          VERSION      ${PROJECT_VERSION}
                          SOVERSION    ${PROJECT_SOVERSION}
                          EXPORT_NAME  QtAccountsService
)

ecm_generate_headers(QtAccountsService_CamelCase_HEADERS
  HEADER_NAMES
    AccountsManager
    UserAccount
    UsersModel
  PREFIX
    QtAccountsService
  REQUIRED_HEADERS QtAccountsService_HEADERS
)
install(FILES ${QtAccountsService_CamelCase_HEADERS}
        DESTINATION ${QTACCOUNTSSERVICE_INCLUDEDIR}/QtAccountsService
        COMPONENT Devel)

install(TARGETS QtAccountsService EXPORT QtAccountsServiceTargets ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})

install(
    FILES
      ${CMAKE_CURRENT_BINARY_DIR}/qtaccountsservice/qtaccountsservice_export.h
      ${QtAccountsService_HEADERS}
      accountsmanager.h
      useraccount.h
      usersmodel.h
    DESTINATION
      ${QTACCOUNTSSERVICE_INCLUDEDIR}/qtaccountsservice
    COMPONENT
      Devel
)

# Create a Config.cmake and a ConfigVersion.cmake file and install them
set(CMAKECONFIG_INSTALL_DIR "${CMAKECONFIG_INSTALL_PREFIX}/QtAccountsService")

ecm_configure_package_config_file("${CMAKE_CURRENT_SOURCE_DIR}/QtAccountsServiceConfig.cmake.in"
                                  "${CMAKE_CURRENT_BINARY_DIR}/QtAccountsServiceConfig.cmake"
                                  INSTALL_DESTINATION  ${CMAKECONFIG_INSTALL_DIR}
                                  )

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/QtAccountsServiceConfig.cmake"
              "${CMAKE_CURRENT_BINARY_DIR}/QtAccountsServiceConfigVersion.cmake"
        DESTINATION "${CMAKECONFIG_INSTALL_DIR}"
        COMPONENT Devel)

install(EXPORT QtAccountsServiceTargets
        DESTINATION "${CMAKECONFIG_INSTALL_DIR}"
        FILE QtAccountsServiceTargets.cmake NAMESPACE QtAccountsService::)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/qtaccountsservice_version.h
        DESTINATION ${QTACCOUNTSSERVICE_INCLUDEDIR}/qtaccountsservice COMPONENT Devel)
