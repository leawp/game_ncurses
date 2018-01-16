cmake_minimum_required(VERSION 3.9)
set(CMAKE_C_STANDARD 11)
project(game_ncurses C)

set( CMAKE_INCLUDE_PATH "/usr/include")
set( CMAKE_LIBRARY_PATH "/lib/x86_64-linux-gnu/libncurses.so.5")

find_package( Curses REQUIRED )
include_directories( ${CURSES_INCLUDE_DIRS} )


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -lncurses")


configure_file(map.txt map.txt COPYONLY)
add_executable(game_ncurses main.c types.h user_input.c user_input.h types.c draw.c draw.h player.c player.h map.c map.h)
target_link_libraries(game_ncurses ${CURSES_LIBRARIES})
