set(PUBLIC_CLASSES
    AccountsManager
    UserAccount
    UsersModel
)

# Create the portable headers
include(CreatePortableHeaders)
create_portable_headers(PORTABLE_HEADERS ${PUBLIC_CLASSES})

install(FILES accountsservice_global.h ${PORTABLE_HEADERS}
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/QtAccountsService)
