# SPDX-FileCopyrightText: 2023 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
# SPDX-License-Identifier: BSD-3-Clause

## Enable feature summary at the end of the configure run:
include(FeatureSummary)

## Find Qt:
find_package(Qt6
    REQUIRED
    COMPONENTS
        Core
        DBus
        Qml
        QmlIntegration
        Quick
        QuickTest
)

#### Features

option(QTACCOUNTSSERVICE_WITH_EXAMPLES "Build examples" ON)
add_feature_info("QtAccountsService Examples" QTACCOUNTSSERVICE_WITH_EXAMPLES "Build QtAccountsService examples")

## Features summary:
if(NOT LIRI_SUPERBUILD)
    feature_summary(WHAT ENABLED_FEATURES DISABLED_FEATURES)
endif()
