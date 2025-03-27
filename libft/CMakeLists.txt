cmake_minimum_required(VERSION 3.31)
project(libft C)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCE_FILES "src/*.c")

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)
