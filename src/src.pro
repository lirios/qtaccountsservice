TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS = accountsservice

!isEmpty(QT.quick.name) {
    src_imports.subdir = imports
    src_imports.depends = accountsservice

    SUBDIRS += src_imports
}
