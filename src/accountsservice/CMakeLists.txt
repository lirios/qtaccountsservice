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
                       ${CMAKE_SOURCE_DIR}/data/interfaces/org.freedesktop.Accounts.User.xml
                       user_interface)
qt5_add_dbus_interface(SOURCES
                       ${CMAKE_SOURCE_DIR}/data/interfaces/org.freedesktop.Accounts.xml
                       accounts_interface)

add_library(qtaccountsservice-qt5 SHARED ${SOURCES})
target_link_libraries(qtaccountsservice-qt5
                      Qt5::Core
                      Qt5::DBus
)
set_target_properties(qtaccountsservice-qt5 PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_SOVERSION})
install(TARGETS qtaccountsservice-qt5
        EXPORT QtAccountsServiceTargets ${INSTALL_TARGETS_DEFAULT_ARGS}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${HEADERS}
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/QtAccountsService)
