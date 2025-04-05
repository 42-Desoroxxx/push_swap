cmake_minimum_required(VERSION 3.22.1)
project(push_swap C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -Ofast -march=native -flto")

add_subdirectory(libft)

set(SOURCES
	src/push_swap.c
	src/operations/operations_printer.c
	src/operations/push_operations.c
	src/operations/rotate_operations.c
	src/operations/swap_operations.c
	src/utils/stack_utils.c
	src/utils/algorithm_utils.c
	src/algorithms/three_sort.c
	src/algorithms/meow_sort.c
	src/algorithms/butterfly_sort.c
	)

add_executable(push_swap ${SOURCES})

target_include_directories(push_swap PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)

target_link_libraries(push_swap PRIVATE libft)
