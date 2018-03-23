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
			rot->y = dat[i][j]->pos->y * cos(0.00005 * RAD)
					 + dat[i][j]->pos->z * sin(0.00005 * RAD);
			rot->z = dat[i][j]->pos->y * -sin(0.00005 * RAD)
					 + dat[i][j]->pos->z * cos(0.00005 * RAD);
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
			rot->y = dat[i][j]->pos->y * cos(1.2 * RAD) - dat[i][j]->pos->z * sin(1.2 * RAD);
			rot->z = dat[i][j]->pos->y * sin(1.2 * RAD) + dat[i][j]->pos->z * cos(1.2 * RAD);
			dat[i][j]->pos->y = rot->y;
			dat[i][j]->pos->z = rot->z;
		}
	}
	draw_model(mlx, model);
}

void		x_rotate_key(int key, t_fdf *fdf)
{
	t_mat4 *rotation;
	t_model *model;
	if (key == 126 || key == 65363)
	{

//		rotate_X((*fdf).mlx, (*fdf).model);
		rotation = create_x_rotation(1);
		model = transform_model(rotation, fdf->model);
		//model = transform_model(fdf->cam, model);
		print_model(model);
		mlx_clear_window(fdf->mlx->mlx, fdf->mlx->win);
		draw_origin(fdf->mlx, fdf->cam);
		draw_model(fdf->mlx, model);
	}
	else
	{
		back_rotate_X((*fdf).mlx, (*fdf).model);
	}
	draw_origin((*fdf).mlx->mlx, (*fdf).cam);
}
