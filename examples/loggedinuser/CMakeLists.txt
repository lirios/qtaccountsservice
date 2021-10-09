liri_add_executable(loggedinuser
    SOURCES
        loggedinuser.qml
        main.cpp
    RESOURCES
        resources.qrc
    LIBRARIES
        Qt5::Core
        Qt5::Gui
        Qt5::Qml
    NO_TARGET_INSTALLATION
)

liri_finalize_executable(loggedinuser)
