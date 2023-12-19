cmake_minimum_required(VERSION 3.0)
project(readutil)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB SOURCE_FILES ${SOURCE_DIR}/*.cpp ${SOURCE_DIR}/*.hpp)
file(GLOB HEADER_FILES ${INCLUDE_DIR}/*.hpp)

include_directories(${INCLUDE_DIR})
add_executable(readto ${SOURCE_FILES} ${HEADER_FILES})
