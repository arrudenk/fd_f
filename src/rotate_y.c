/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 00:37:49 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/30 00:37:51 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	rotate_y(t_fdf fdf, int mod)
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
			rot.x = dat[i][j]->pos.x * cos(mod * 1.2 * RAD) +
					dat[i][j]->pos.z * sin(mod * 1.2 * RAD);
			rot.z = -dat[i][j]->pos.x * sin(mod * 1.2 * RAD) +
					dat[i][j]->pos.z * cos(mod * 1.2 * RAD);
			dat[i][j]->pos.x = rot.x;
			dat[i][j]->pos.z = rot.z;
		}
	}
	draw_model(fdf.mlx, fdf.model, fdf.random);
}

void		y_rotate_key(int key, t_fdf *fdf)
{
	if (key == UP || key == 65362)
	{
		rotate_y(*fdf, 1);
	}
	if (key == DOWN || key == 65364)
	{
		rotate_y(*fdf, -1);
	}
}
