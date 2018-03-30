/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 00:37:54 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/30 00:37:55 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	rotate_z(t_mlx *mlx, t_model *model, int turn)
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
			rot->x = dat[i][j]->pos->x * cos(turn * 1.2 * RAD) +
					dat[i][j]->pos->y * sin(turn * 1.2 * RAD);
			rot->y = dat[i][j]->pos->x * -sin(turn * 1.2 * RAD) +
					dat[i][j]->pos->y * cos(turn * 1.2 * RAD);
			dat[i][j]->pos->x = rot->x;
			dat[i][j]->pos->y = rot->y;
		}
	}
	draw_model(mlx, model);
}

void		z_rotate_key(int key, t_fdf *fdf)
{
	if (key == PLUS)
	{
		rotate_z((*fdf).mlx, (*fdf).model, 1);
	}
	if (key == MINUS)
	{
		rotate_z((*fdf).mlx, (*fdf).model, -1);
	}
}
