QT += dbus
TEMPLATE = lib
TARGET = Qt5AccountsService

DEFINES += QT_ACCOUNTSSERVICE_LIB
CONFIG += debug
DBUS_INTERFACES = ../../data/interfaces/org.freedesktop.Accounts.User.xml \
                  ../../data/interfaces/org.freedesktop.Accounts.xml

SOURCES += accountsmanager.cpp \
           useraccount.cpp
