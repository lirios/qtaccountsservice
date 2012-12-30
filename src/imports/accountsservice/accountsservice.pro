QT += qml quick accountsservice-private

LIBS += -L$$QT.accountsservice.libs

SOURCES += main.cpp

load(qml_plugin)
