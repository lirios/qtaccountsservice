qt6_add_executable(listusers
    main.cpp
)

target_link_libraries(listusers
    PRIVATE
        Qt6::Core
        Liri::Qt6AccountsService
)
