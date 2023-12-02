set(SOURCES
    main.cpp
    userslistview.qml
)

qt6_add_resources(SOURCES resources.qrc)

qt6_add_executable(userslistview ${SOURCES})

target_link_libraries(userslistview
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
)
