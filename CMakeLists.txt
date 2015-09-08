cmake_minimum_required(VERSION 2.6)

SET(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/../../toolchain/Prizm.cmake)

set(project_name rogue)
project(${project_name})

file(GLOB SRC "${CMAKE_SOURCE_DIR}/src/*.c")

add_executable(${project_name} ${SRC})

makeg3a("${CMAKE_BINARY_DIR}/${project_name}" ${project_name} "${CMAKE_SOURCE_DIR}/unselected.bmp" "${CMAKE_SOURCE_DIR}/selected.bmp")
