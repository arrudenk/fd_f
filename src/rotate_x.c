#include "../include/fdf.h"

static void	rotate_x(t_mlx *mlx, t_model *model, int mod)
{
	int		i;
	int		j;
	t_vec3	*rot;
	t_point	***dat;

	i = -1;
	j = -1;
	rot = new_vec3(0, 0, 0);
	dat = model->data;
	while (++i < model->size_x)
	{
		j = -1;
		while (++j < model->size_y)
		{
			rot->y = dat[i][j]->pos->y * cos(mod * 1.2 * RAD) +
					dat[i][j]->pos->z * sin(mod * 1.2 * RAD);
			rot->z = dat[i][j]->pos->y * -sin(mod * 1.2 * RAD) +
					dat[i][j]->pos->z * cos(mod * 1.2 * RAD);
			dat[i][j]->pos->y = rot->y;
			dat[i][j]->pos->z = rot->z;
		}
	}
	draw_model(mlx, model);
}

void		x_rotate_key(int key, t_fdf *fdf)
{
	if (key == 124 || key == 65363)
	{
		rotate_x((*fdf).mlx, (*fdf).model, 1);
	}
	else
	{
		rotate_x((*fdf).mlx, (*fdf).model, -1);
	}
}
