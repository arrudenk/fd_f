cmake_minimum_required(VERSION 3.8)
project(fd_f)

set(CMAKE_C_STANDARD 99)

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(MLX -lft -lmlx -lXext -lX11 -lm)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    # Tbma, do you OSX stuff here

    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit -lm")
    link_directories(${PROJECT_SOURCE_DIR}/libft)
    include_directories(${PROJECT_SOURCE_DIR}/libft)
    target_link_libraries(fd_f -lft -lm)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")


set(SOURCE_FILES src/main.c include/fdf.h
        src/draw.c src/vector_math.c include/vector_math.h)

add_executable(fd_f ${SOURCE_FILES})

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_link_libraries(fd_f ${MLX})
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
