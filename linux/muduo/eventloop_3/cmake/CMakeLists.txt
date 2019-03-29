cmake_minimum_required(VERSION 2.6)

project(eventloop CXX)
message(STATUS ${eventloop_VERSION})
message(STATUS ${PROJECT_VERSION})
set(CXX_FLAGS
 -g
 -Wall
 # -Wextra
 # -Werror
)

string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(CMAKE_CXX_COMPILER "g++")

set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -finline-limit=1000 -DNDEBUG")

aux_source_directory(../src/ DIR_SRCS)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(eventloop ${DIR_SRCS})
target_link_libraries(eventloop pthread rt)

