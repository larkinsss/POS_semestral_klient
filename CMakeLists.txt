cmake_minimum_required(VERSION 3.7)
project(POS_semestral_klient C)

set(CMAKE_C_STANDARD 99)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(POS_semestral_klient main.c)
target_link_libraries(POS_semestral_klient ${CURSES_LIBRARIES})