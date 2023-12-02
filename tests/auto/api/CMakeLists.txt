set(SOURCES
    fakeaccounts.cpp fakeaccounts.h
    fakeuser.cpp fakeuser.h
    tst_api.cpp
)

qt6_add_dbus_adaptor(
    SOURCES
    ../../../src/accountsservice/org.freedesktop.Accounts.xml
    fakeaccounts.h
    FakeAccounts
)
qt6_add_dbus_adaptor(
    SOURCES
    ../../../src/accountsservice/org.freedesktop.Accounts.User.xml
    fakeuser.h
    FakeUser
)

add_executable(tst_qtaccountsservice ${SOURCES})

target_link_libraries(tst_qtaccountsservice PRIVATE Liri::Qt6AccountsService)
