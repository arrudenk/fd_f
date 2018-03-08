cmake_minimum_required(VERSION 3.8)
project(fd_f)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit -lm")
link_directories(${PROJECT_SOURCE_DIR}/libft)
include_directories(${PROJECT_SOURCE_DIR}/libft)
set(SOURCE_FILES src/main.c include/fdf.h
        src/draw.c)

add_executable(fd_f ${SOURCE_FILES})
target_link_libraries(fd_f -lft)