TARGET = QtAccountsService
MODULE = QtAccountsService

QT += core dbus
QT_PRIVATE += core-private
CONFIG += liri_create_cmake

DBUS_INTERFACES += \
    $$PWD/org.freedesktop.Accounts.xml \
    $$PWD/org.freedesktop.Accounts.User.xml

HEADERS += \
    $$PWD/accountsmanager.h \
    $$PWD/useraccount.h \
    $$PWD/usersmodel.h

SOURCES += \
    $$PWD/accountsmanager.cpp \
    $$PWD/useraccount.cpp \
    $$PWD/usersmodel.cpp

QMAKE_PKGCONFIG_NAME = QtAccountsService
QMAKE_PKGCONFIG_DESCRIPTION = Qt wrapper to Accounts Service
QMAKE_PKGCONFIG_PREFIX = $$LIRI_INSTALL_PREFIX
QMAKE_PKGCONFIG_LIBDIR = $$target.path
QMAKE_PKGCONFIG_INCDIR = $$headers.path
QMAKE_PKGCONFIG_VERSION = $$QTACCOUNTSSERVICE_VERSION
QMAKE_PKGCONFIG_DESTDIR = pkgconfig

load(liri_qt_module)
