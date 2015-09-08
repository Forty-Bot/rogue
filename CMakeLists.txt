cmake_minimum_required(VERSION 2.6)

message(STATUS "CMAKE_C_FLAGS: " ${CMAKE_C_FLAGS})
SET(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/../../toolchain/Prizm.cmake)
message(STATUS "CMAKE_C_FLAGS: " ${CMAKE_C_FLAGS})

set(project_name rogue)
message(STATUS "CMAKE_C_FLAGS: " ${CMAKE_C_FLAGS})
project(${project_name})
message(STATUS "CMAKE_C_FLAGS: " ${CMAKE_C_FLAGS})

file(GLOB SRC "${CMAKE_SOURCE_DIR}/src/*.c")
message(STATUS "SRC: " ${SRC})

message(STATUS "CMAKE_C_FLAGS: " ${CMAKE_C_FLAGS})
add_executable(${project_name} ${SRC})
message(STATUS "CMAKE_C_FLAGS: " ${CMAKE_C_FLAGS})

makeg3a("${CMAKE_BINARY_DIR}/${project_name}" ${project_name} "${CMAKE_SOURCE_DIR}/unselected.bmp" "${CMAKE_SOURCE_DIR}/selected.bmp")
