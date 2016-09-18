include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../headers"
    "${CMAKE_CURRENT_BINARY_DIR}/../../../headers"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/accountsservice"
)

add_library(declarative_accountsservice SHARED main.cpp)
target_link_libraries(declarative_accountsservice
                      Qt5::Core
                      Qt5::Gui
                      Qt5::Qml
                      Qt5::Quick
                      QtAccountsService::QtAccountsService
)
install(TARGETS declarative_accountsservice
        LIBRARY DESTINATION ${QML_INSTALL_DIR}/QtAccountsService)
install(FILES plugins.qmltypes qmldir
        DESTINATION ${QML_INSTALL_DIR}/QtAccountsService)
