#include "../include/fdf.h"

int		main(int argc, char **argv)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Hello MLX");

	draw_line(mlx_ptr, win_ptr, WIDTH/2, HEIGHT/2, 60, 25, VIOLET);
	draw_line(mlx_ptr, win_ptr, WIDTH/2, HEIGHT/2, WIDTH-60, 25, VIOLET);
	mlx_key_hook(win_ptr, hook_keydown, NULL);

	mlx_loop(mlx_ptr);

	return (0);
}

void 	draw_line(void* mlx_ptr, void* win_ptr, double x1, double y1, double x2, double y2, int color) {
	double delta_x;
	double delta_y;
	double delta_error;
	double y;
	double error;
	double startX;
	double endX;
	double direction_y;

	error = 0;
	delta_x = fabs(x2-x1);
	delta_y = fabs(y2-y1);
	delta_error = delta_y/delta_x;

	direction_y = (y2-y1) > 0 ? 1 : -1;
	startX = (x2-x1) > 0 ? x1 : x2;
	endX = (x2-x1) > 0 ? x2 : x1;

	while (startX < endX)
	{
		y = ((y2 - y1)/(x2 - x1)) * (startX - x1) + y1;
		mlx_pixel_put(mlx_ptr, win_ptr, startX, y, color);
		error += delta_error;

		/*if (error >= 0.45) {
			y += direction_y;
			error--;
		}*/

		startX++;
	}
}

int		hook_keydown(int key)
{
	if (key == 65307)
		exit(1);
	return (0);
}