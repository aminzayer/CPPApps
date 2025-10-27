cmake_minimum_required(VERSION 3.10)

project(CodeCleanup)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add an executable
add_executable(main src/main.cpp
                    src/ciphers/CaesarCipher.cpp
                    src/string_utils/StringUtils.cpp
                    src/stats/RealtimeStats.cpp)

# Include directories
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
