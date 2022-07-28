cmake_minimum_required(VERSION 3.22)
project(cmake_travis VERSION 0.0.9)

find_package(Threads REQUIRED)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in ${PROJECT_SOURCE_DIR}/version.h)

set(CMAKE_CXX_STANDARD 20)

add_executable(cmake_travis main.cpp)

add_library(mylib lib.cpp)

add_executable(test_version test_version.cpp)

set_target_properties(cmake_travis mylib test_version PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra")

set_target_properties(test_version PROPERTIES
        COMPILE_DEFINITION BOOST_TEST_DYNAMIC_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR})

target_link_libraries(cmake_travis
        mylib
        Threads::Threads)

target_link_libraries(test_version
        ${Boost_LIBRARIES}
        mylib)

install(TARGETS cmake_travis RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT shebdim@gmail.com)

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

enable_testing()

add_test(helloworld_tests test_version)

