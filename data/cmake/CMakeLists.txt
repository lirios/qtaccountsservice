include(CMakePackageConfigHelpers)

set(CMAKECONFIG_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/QtAccountsService")

configure_package_config_file("${CMAKE_CURRENT_SOURCE_DIR}/QtAccountsServiceConfig.cmake.in"
                              "${CMAKE_CURRENT_BINARY_DIR}/QtAccountsServiceConfig.cmake"
                              INSTALL_DESTINATION  ${CMAKECONFIG_INSTALL_DIR}
                              PATH_VARS CMAKE_INSTALL_PREFIX CMAKE_INSTALL_INCLUDEDIR)
write_basic_package_version_file("${CMAKE_CURRENT_BINARY_DIR}/QtAccountsServiceConfigVersion.cmake"
                                 VERSION ${PROJECT_VERSION}
                                 COMPATIBILITY AnyNewerVersion)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/QtAccountsServiceConfig.cmake"
              "${CMAKE_CURRENT_BINARY_DIR}/QtAccountsServiceConfigVersion.cmake"
        DESTINATION "${CMAKECONFIG_INSTALL_DIR}"
        COMPONENT Devel)
install(EXPORT QtAccountsServiceTargets
        DESTINATION "${CMAKECONFIG_INSTALL_DIR}"
        FILE QtAccountsServiceTargets.cmake
        NAMESPACE QtAccountsService::)
