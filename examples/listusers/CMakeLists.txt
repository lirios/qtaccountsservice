liri_add_executable(listusers
    SOURCES
        main.cpp
    LIBRARIES
        Qt6::Core
        Liri::Qt6AccountsService
    NO_TARGET_INSTALLATION
)

liri_finalize_executable(listusers)
