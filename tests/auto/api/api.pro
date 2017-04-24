TARGET = tst_api

osx:CONFIG -= app_bundle

QT += core dbus testlib QtAccountsService

CONFIG += testcase

DBUS_ADAPTORS += \
    $$QTACCOUNTSSERVICE_SOURCE_TREE/src/accountsservice/org.freedesktop.Accounts.xml \
    $$QTACCOUNTSSERVICE_SOURCE_TREE/src/accountsservice/org.freedesktop.Accounts.User.xml

HEADERS += \
    $$PWD/fakeaccounts.h \
    $$PWD/fakeuser.h

SOURCES += \
    $$PWD/fakeaccounts.cpp \
    $$PWD/fakeuser.cpp \
    $$PWD/tst_api.cpp
