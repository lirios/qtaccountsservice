include(ECMMarkAsTest)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/../../src/accountsservice"
    "${CMAKE_CURRENT_BINARY_DIR}/../../src/accountsservice"
)

find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED Test)

set(SOURCES
    fakeaccounts.cpp
    fakeuser.cpp
    tst_api.cpp
)

qt5_add_dbus_adaptor(SOURCES
                     "${CMAKE_CURRENT_SOURCE_DIR}/../../src/accountsservice/org.freedesktop.Accounts.xml"
                     fakeaccounts.h FakeAccounts
                     fakeaccountsadaptor FakeAccountsAdaptor)
qt5_add_dbus_adaptor(SOURCES
                     "${CMAKE_CURRENT_SOURCE_DIR}/../../src/accountsservice/org.freedesktop.Accounts.User.xml"
                     fakeuser.h FakeUser
                     fakeuseradaptor FakeUserAdaptor)

add_executable(tst_api ${SOURCES})
target_link_libraries(tst_api Qt5::Test QtAccountsService)
add_test(test-api tst_api)
ecm_mark_as_test(tst_api)
