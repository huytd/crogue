cmake_minimum_required(VERSION 3.10)

project(crogue)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

file(GLOB MAIN_SOURCES CONFIGURE_DEPENDS
	"engine/*.c"
	"render/**/*.c"
	"src/*.c"
)

include_directories(${CMAKE_SOURCE_DIR}/engine)
include_directories(${CMAKE_SOURCE_DIR}/render/term)

add_compile_options(-Wall -Wextra -Werror -fsanitize=address)
add_link_options(-fsanitize=address)

add_executable(crogue ${MAIN_SOURCES})

target_link_libraries(crogue ncurses)
