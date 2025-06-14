cmake_minimum_required(VERSION 3.10)
project(AVScanner LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(avscanner
        src/main.cpp
        src/scanner.cpp
        src/signatures.cpp
)

target_include_directories(avscanner PRIVATE include)

add_executable(test_scanner
        tests/test_scanner.cpp
        src/scanner.cpp
        src/signatures.cpp
)
target_include_directories(test_scanner PRIVATE include)
