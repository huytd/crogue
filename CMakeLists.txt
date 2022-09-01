cmake_minimum_required(VERSION 3.10)

project(Crogue)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

file(GLOB MAIN_SOURCES CONFIGURE_DEPENDS "src/*.c")

add_executable(crogue ${MAIN_SOURCES})

include_directories(${CMAKE_SOURCE_DIR}/include)

target_link_libraries(crogue ncurses)
