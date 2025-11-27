cmake_minimum_required(VERSION 4.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Qt5Widgets)

add_executable(rfrakt rfrakt.cpp)

add_executable(qrfrakt qrfrakt.cpp)
target_link_libraries(qrfrakt Qt5::Widgets)

install(TARGETS qrfrakt rfrakt)

# EOF #
