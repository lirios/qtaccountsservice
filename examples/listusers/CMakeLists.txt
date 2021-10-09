liri_add_executable(listusers
    SOURCES
        main.cpp
    LIBRARIES
        Qt5::Core
        Liri::Qt5AccountsService
    NO_TARGET_INSTALLATION
)

liri_finalize_executable(listusers)
