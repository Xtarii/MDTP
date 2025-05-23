cmake_minimum_required(VERSION 3.30)
project(MDTP)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Header files directory
include_directories(include)

# Library ( C++ Files )
add_library(MDTP STATIC src/library.cpp
        src/parser/header/MDTPHeader.cpp
        src/parser/parser.cpp
        src/socket/AbstractBaseSocket.cpp
        src/socket/MDTPServer.cpp
        src/socket/MDTPClient.cpp
        src/socket/connection/MDTPConnection.cpp
        src/data/MDTPOptions.cpp)



# Library Tests
add_executable(test .test/main.cpp)
target_link_libraries(test PRIVATE MDTP)
