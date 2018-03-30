cmake_minimum_required(VERSION 3.8)
project(fd_f)

set(CMAKE_C_STANDARD 99)

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(MLX -lft -lmlx -lXext -lX11 -lm)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    # Tbma, do you OSX stuff here
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit -lm")
    link_directories(${PROJECT_SOURCE_DIR}/minilibx_macos)
    include_directories(${PROJECT_SOURCE_DIR}/minilibx_macos)
    link_directories(${PROJECT_SOURCE_DIR}/libft)
    include_directories(${PROJECT_SOURCE_DIR}/libft)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")


set(SOURCE_FILES src/main.c include/fdf.h
        src/draw.c src/vector_math.c include/vector_math.h src/create_model.c src/hex_to_dec.c src/rotate_x.c src/rotate_y.c src/rotate_z.c src/rotate_matrix.c src/new_vec.c src/vec_tools.c src/camera.c src/matrix_math.c src/model_tools.c src/color.c src/mlx.c "src/create_image.c" include/keys.h src/debug_tools.c src/free_tools.c src/destroy_height.c)

add_executable(fd_f ${SOURCE_FILES})
IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    target_link_libraries(fd_f -lft -lm)
    target_link_libraries(fd_f -lft -lmlx -lm)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_link_libraries(fd_f ${MLX})
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
