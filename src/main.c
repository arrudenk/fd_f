//
// Created by arrudnek on 06.03.18.
//
#include <mlx.h>

int		main(int argc, char **argv)
{
	void *mlx_ptr;

	mlx_ptr = mlx_init();
	mlx_new_window(mlx_ptr, 640, 480, "Hello MLX");
	mlx_loop(mlx_ptr);
	return (0);
}