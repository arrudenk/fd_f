/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_z.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:22:20 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/23 17:26:14 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		rotate_Z(t_mlx *mlx, t_model *model)
{
	int		i;
	int		j;
	t_vec3	*rot;
	t_point	***dat;

	i = -1;
	j = -1;
	rot = new_vec3(0, 0, 0);
	dat = (t_point ***)model->data;
	while (++i < model->size_x)
	{
		j = -1;
		while (++j < model->size_y)
		{
			rot->x = dat[i][j]->pos->x * cos(1.2 * RAD)
					 + dat[i][j]->pos->y * sin(1.2 * RAD);
			rot->y = dat[i][j]->pos->x * -sin(1.2 * RAD)
					 + dat[i][j]->pos->y * cos(1.2 * RAD);
			dat[i][j]->pos->x = rot->x;
			dat[i][j]->pos->y = rot->y;
		}
	}
	draw_model(mlx, model);
}

void		back_rotate_Z(t_mlx *mlx, t_model *model)
{
	int		i;
	int		j;
	t_vec3	*rot;
	t_point	***dat;

	i = -1;
	j = -1;
	rot = new_vec3(0, 0, 0);
	dat = (t_point ***)model->data;
	while (++i < model->size_x)
	{
		j = -1;
		while (++j < model->size_y)
		{
			rot->x = dat[i][j]->pos->x * cos(1.2 * RAD)
					- dat[i][j]->pos->y * sin(1.2 * RAD);
			rot->y = dat[i][j]->pos->x * -sin(1.2 * RAD)
					- dat[i][j]->pos->y * cos(1.2 * RAD);
			dat[i][j]->pos->x = rot->x;
			dat[i][j]->pos->y = rot->y;
		}
	}
	draw_model(mlx, model);
}
