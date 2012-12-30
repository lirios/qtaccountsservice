TEMPLATE = subdirs
CONFIG += ordered
!isEmpty(QT.dbus.name): SUBDIRS = accountsservice
