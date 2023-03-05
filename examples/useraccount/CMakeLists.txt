liri_add_executable(useraccount
    SOURCES
        main.cpp
        useraccount.qml
    RESOURCES
        resources.qrc
    LIBRARIES
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
    NO_TARGET_INSTALLATION
)

liri_finalize_executable(useraccount)
