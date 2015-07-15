include_directories(
    ${CMAKE_SOURCE_DIR}/headers
    ${CMAKE_BINARY_DIR}/headers
    ${CMAKE_SOURCE_DIR}/src/accountsservice
)

add_library(declarative_accountsservice SHARED main.cpp)
qt5_use_modules(declarative_accountsservice Qml Quick)
target_link_libraries(declarative_accountsservice qtaccountsservice-qt5)
install(TARGETS declarative_accountsservice
        LIBRARY DESTINATION ${KDE_INSTALL_QMLDIR}/QtAccountsService)
install(FILES plugins.qmltypes qmldir
        DESTINATION ${KDE_INSTALL_QMLDIR}/QtAccountsService)
