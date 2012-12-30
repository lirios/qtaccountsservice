TARGET = QtAccountsService
QT = dbus
TEMPLATE = lib

#QMAKE_DOCS = $$PWD/doc/qtaccountsservice.docconf
load(qt_module)

DEFINES += QT_ACCOUNTSSERVICE_LIB
#CONFIG += debug create_cmake
DBUS_INTERFACES = ../../data/interfaces/org.freedesktop.Accounts.User.xml \
                  ../../data/interfaces/org.freedesktop.Accounts.xml

SOURCES += accountsmanager.cpp \
           useraccount.cpp

PRIVATE_HEADERS += accountsmanager_p.h \
                   useraccount_p.h
                   
PUBLIC_HEADERS += accountsmanager.h \
                  useraccount.h

HEADERS += $$PUBLIC_HEADERS $$PRIVATE_HEADERS
