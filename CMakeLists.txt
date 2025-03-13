cmake_minimum_required(VERSION 3.29)
project(libft C)

add_subdirectory(libft)

file(GLOB SOURCE_FILES "src/*.c")

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes ${CMAKE_CURRENT_SOURCE_DIR}/libft/includes)

target_link_libraries(${PROJECT_NAME} PRIVATE ft)
