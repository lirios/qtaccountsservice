include_directories(
    ${CMAKE_SOURCE_DIR}/headers
    ${CMAKE_BINARY_DIR}/headers
    ${CMAKE_SOURCE_DIR}/src/accountsservice
)

add_library(declarative_accountsservice SHARED main.cpp)
set_target_properties(declarative_accountsservice PROPERTIES PREFIX "")
qt5_use_modules(declarative_accountsservice Qml Quick)
install(TARGETS declarative_accountsservice
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/hawaii/qml/QtAccountsService)
