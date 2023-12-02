set(SOURCES
    main.cpp
    useraccount.qml
)

qt6_add_resources(SOURCES resources.qrc)

qt6_add_executable(useraccount ${SOURCES})

target_link_libraries(useraccount
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
)
