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

static void	rotate_z(t_fdf fdf, int turn)
{
	int		i;
	int		j;
	t_vec3	rot;
	t_point	***dat;

	i = -1;
	rot = vec3(0, 0, 0);
	dat = fdf.model->data;
	while (++i < fdf.model->size_x)
	{
		j = -1;
		while (++j < fdf.model->size_y)
		{
			rot.x = dat[i][j]->pos.x * cos(turn * 1.2 * RAD) +
					dat[i][j]->pos.y * sin(turn * 1.2 * RAD);
			rot.y = dat[i][j]->pos.x * -sin(turn * 1.2 * RAD) +
					dat[i][j]->pos.y * cos(turn * 1.2 * RAD);
			dat[i][j]->pos.x = rot.x;
			dat[i][j]->pos.y = rot.y;
		}
	}
	draw_model(fdf.mlx, fdf.model, fdf.random);
}

void		z_rotate_key(int key, t_fdf *fdf)
{
	if (key == PLUS)
	{
		rotate_z(*fdf, 1);
	}
	if (key == MINUS)
	{
		rotate_z(*fdf, -1);
	}
}
