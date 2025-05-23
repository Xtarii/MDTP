cmake_minimum_required(VERSION 3.30)
project(MDTP)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



# Library ( C++ Files )
add_library(MDTP STATIC src/library.cpp
        src/parser/header/MDTPHeader.cpp
        src/parser/parser.cpp
        src/socket/AbstractBaseSocket.cpp
        src/socket/MDTPServer.cpp
        src/socket/MDTPClient.cpp
        src/socket/connection/MDTPConnection.cpp
        src/data/MDTPOptions.cpp)



# Header files directory
include_directories(include)
target_include_directories(MDTP PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)



# Fetch Content and Github
include(GNUInstallDirs)

install(TARGETS MDTP EXPORT MDTPTargets)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT MDTPTargets
    FILE MDTPTargets.cmake
    NAMESPACE MDTP::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/mdtp
)



# Library Tests
#add_executable(test .test/main.cpp)
#target_link_libraries(test PRIVATE MDTP)
