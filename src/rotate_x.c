/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_x.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:25:46 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/22 15:12:09 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		rotate_X(t_mlx *mlx, t_model *model)
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
			rot->y = dat[i][j]->pos->y * cos(1.2 * RADIANE)
					 + dat[i][j]->pos->z * sin(1.2 * RADIANE);
			rot->z = dat[i][j]->pos->y * -sin(1.2 * RADIANE)
					 + dat[i][j]->pos->z * cos(1.2 * RADIANE);
			dat[i][j]->pos->y = rot->y;
			dat[i][j]->pos->z = rot->z;
		}
	}

	draw_model(mlx, model);
}

void		back_rotate_X(t_mlx *mlx, t_model *model)
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
			rot->y = dat[i][j]->pos->y * cos(1.2 * RADIANE)
					 - dat[i][j]->pos->z * sin(1.2 * RADIANE);
			rot->z = dat[i][j]->pos->y * sin(1.2 * RADIANE)
					 + dat[i][j]->pos->z * cos(1.2 * RADIANE);
			dat[i][j]->pos->y = rot->y;
			dat[i][j]->pos->z = rot->z;
		}
	}
	draw_model(mlx, model);
}

void		x_rotate_key(int key, t_fdf *fdf)
{
	if (key == 126)
	{
		rotate_X((*fdf).mlx, (*fdf).model);
	}
	if (key == 125)
	{
		back_rotate_X((*fdf).mlx, (*fdf).model);
	}
	draw_origin((*fdf).mlx->mlx, (*fdf).cam);
}
