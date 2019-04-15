cmake_minimum_required(VERSION 3.10.0)

project("QtAccountsService"
    VERSION "1.3.0"
    DESCRIPTION "Qt-style API for Accounts Service"
    LANGUAGES CXX C
)

## Shared macros and functions:
if(NOT LIRI_LOCAL_ECM)
    find_package(LiriCMakeShared "1.0.0" REQUIRED NO_MODULE)
    list(APPEND CMAKE_MODULE_PATH "${LCS_MODULE_PATH}")
endif()

## Set minimum versions required:
set(QT_MIN_VERSION "5.8.0")

## Liri specific setup common for all modules:
include(LiriSetup)

## Features:
option(QTACCOUNTSSERVICE_WITH_EXAMPLES "Build examples" ON)
add_feature_info("QtAccountsService Examples" QTACCOUNTSSERVICE_WITH_EXAMPLES "Build QtAccountsService examples")

## Find Qt 5:
find_package(Qt5 "${QT_MIN_VERSION}"
    CONFIG REQUIRED
    COMPONENTS
        Core
        DBus
        Gui
        Qml
        Quick
        QuickTest
)

## Add subdirectories:
add_subdirectory(src/accountsservice)
if(QTACCOUNTSSERVICE_WITH_EXAMPLES)
    add_subdirectory(examples/listusers)
    add_subdirectory(examples/loggedinuser)
    add_subdirectory(examples/useraccount)
    add_subdirectory(examples/userslistview)
endif()
add_subdirectory(src/imports/accountsservice)
if(BUILD_TESTING)
    add_subdirectory(tests/auto/api)
endif()
