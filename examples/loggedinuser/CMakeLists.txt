set(SOURCES
    loggedinuser.qml
    main.cpp
)

qt6_add_resources(SOURCES resources.qrc)

qt6_add_executable(loggedinuser ${SOURCES})

target_link_libraries(loggedinuser
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
)
