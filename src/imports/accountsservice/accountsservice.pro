TARGET = qtaccountsserviceplugin
TARGETPATH = QtAccountsService
IMPORT_VERSION = 1.0

QT += qml quick QtAccountsService

SOURCES += $$PWD/main.cpp

CONFIG += no_cxx_module
load(liri_qml_plugin)
