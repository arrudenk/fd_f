cmake_minimum_required(VERSION 3.8)
project(fd_f)

set(CMAKE_C_STANDARD 99)

# You need to download and compile the Libft specificly for you machine
# put header file and .a file in "Libft" folder in your project
link_directories(${PROJECT_SOURCE_DIR}/mlx)
include_directories(${PROJECT_SOURCE_DIR}/mlx)

set(SOURCE_FILES src/main.c include/fdf.h)

add_executable(fd_f ${SOURCE_FILES})
target_link_libraries(fd_f -lmlx -lXext -lX11)
