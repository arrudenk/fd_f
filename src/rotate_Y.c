#include "../include/fdf.h"

static void	rotate_y(t_mlx *mlx, t_model *model, int mod)
{
	int		i;
	int		j;
	t_vec3	*rot;
	t_point	***dat;

	i = -1;
	rot = new_vec3(0, 0, 0);
	dat = model->data;
	while (++i < model->size_x)
	{
		j = -1;
		while (++j < model->size_y)
		{
			rot->x = dat[i][j]->pos->x * cos(mod * 1.2 * RAD) +
					dat[i][j]->pos->z * sin(mod * 1.2 * RAD);
			rot->z = -dat[i][j]->pos->x * sin(mod * 1.2 * RAD) +
					dat[i][j]->pos->z * cos(mod * 1.2 * RAD);
			dat[i][j]->pos->x = rot->x;
			dat[i][j]->pos->z = rot->z;
		}
	}
	draw_model(mlx, model);
}

void		y_rotate_key(int key, t_fdf *fdf)
{
	if (key == 126)
	{
		rotate_y((*fdf).mlx, (*fdf).model, 1);
	}
	if (key == 125)
	{
		rotate_y((*fdf).mlx, (*fdf).model, -1);
	}
}
