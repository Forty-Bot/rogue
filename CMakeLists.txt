cmake_minimum_required(VERSION 2.6)

SET(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/../../toolchain/Prizm.cmake)

set(PROJECT_NAME rogue)
project(${PROJECT_NAME})

file(GLOB SRC "${CMAKE_SOURCE_DIR}/src/*.c")

# Where to stick generated files
set(GENERATED_DIR "${CMAKE_BINARY_DIR}/generated")

add_subdirectory("${CMAKE_SOURCE_DIR}/res/fonts")

# Configure files with cmake variables and add them to the sources
message(STATUS "Configuring source files")
configure_file("${CMAKE_SOURCE_DIR}/src/fonts.c.in" "${GENERATED_DIR}/fonts.c")
file(GLOB GENERATED_SRC "${GENERATED_DIR}/*.c")

include_directories(${GENERATED_DIR} "${CMAKE_SOURCE_DIR}/src")
add_executable(${PROJECT_NAME} ${SRC} ${GENERATED_SRC})
add_dependencies(${PROJECT_NAME} compile_font)

makeg3a("${CMAKE_BINARY_DIR}/${PROJECT_NAME}" ${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/unselected.bmp" "${CMAKE_SOURCE_DIR}/selected.bmp")
