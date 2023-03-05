liri_add_executable(userslistview
    SOURCES
        main.cpp
        userslistview.qml
    RESOURCES
        resources.qrc
    LIBRARIES
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
    NO_TARGET_INSTALLATION
)

liri_finalize_executable(userslistview)
