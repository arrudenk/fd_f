/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                              :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:10:14 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/29 16:10:31 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_line(t_mlx *mlx, t_draw info, int colr)
{
	if (fabs(info.y2 - info.y1) < fabs(info.x2 - info.x1))
	{
		if (info.x1 < info.x2)
			draw_h(mlx, ddddc(info.x1, info.y1, info.x2, info.y2), colr);
		else
			draw_h(mlx, ddddc(info.x2, info.y2, info.x1, info.y1), colr);
	}
	else
	{
		if (info.y1 < info.y2)
			draw_v(mlx, ddddc(info.x1, info.y1, info.x2, info.y2), colr);
		else
			draw_v(mlx, ddddc(info.x2, info.y2, info.x1, info.y1), colr);
	}
}

void	draw_h(t_mlx *mlx, t_draw i, int colr)
{
	double y;
	double start_x;
	double end_y;

	start_x = i.x1;
	end_y = i.x2;
	while (start_x < end_y)
	{
		y = ((i.y2 - i.y1) / (i.x2 - i.x1)) * (start_x - i.x1) + i.y1;
		if (start_x > 0 && y > 0)
			image_set_pixel(mlx, start_x, y, i.colr);
		else
			break ;
		start_x++;
	}
}

void	draw_v(t_mlx *mlx, t_draw i, int colr)
{
	double x;
	double start_y;
	double end_y;

	start_y = i.y1;
	end_y = i.y2;
	while (start_y < end_y)
	{
		x = ((i.x2 - i.x1) / (i.y2 - i.y1)) * (start_y - i.y1) + i.x1;
		if (start_y > 0 && x > 0)
		{
			image_set_pixel(mlx, x, start_y, i.colr);
//			mlx_pixel_put(mlx->mlx, mlx->win, x, start_y, i.colr);
		}
		else
		{
			break ;
		}
		start_y++;
	}
}

void	draw_model(t_mlx *mlx, t_model *model)
{
	int i;
	int j;
	int magic;

	mlx_clear_window(mlx->mlx, mlx->win);
	clear_image(mlx);
	i = -1;
	while (++i < model->size_x)
	{
		j = -1;
		while (++j < model->size_y - 1)
		{
			draw_line(mlx, ddddc(M_X(i, j) + W / 2, M_Y(i, j) + H / 2
					, M_X(i, j + 1) + W / 2, M_Y(i, j + 1) + H / 2), VIOLET);
		}
	}
	i = -1;
	while (++i < model->size_y)
	{
		j = -1;
		while (++j < model->size_x - 1)
		{
			draw_line(mlx, ddddc(M_X(j, i) + W / 2, M_Y(j, i) + H / 2
					, M_X(j + 1, i) + W / 2, M_Y(j + 1, i) + H / 2), VIOLET);
		}
	}

	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->image, 0, 0);
}

void	draw_origin(t_mlx *mlx, t_mat4 *view_matrix)
{
	t_vec4 x;
	t_vec4 y;
	t_vec4 z;
	t_vec4 o;

	x = vec4(view_matrix->x_axis.x * 80, view_matrix->x_axis.y * 80
			, view_matrix->x_axis.z * 80, 1);
	y = vec4(view_matrix->y_axis.x * 80, view_matrix->y_axis.y * 80
			, view_matrix->y_axis.z * 80, 1);
	z = vec4(view_matrix->z_axis.x * 80, view_matrix->z_axis.y * 80
			, view_matrix->z_axis.z * 80, 1);
	o = vec4(view_matrix->w_axis.x, view_matrix->w_axis.y
			, view_matrix->w_axis.z, 1);
	draw_line(mlx, ddddc(o.x + W / 2, o.y + H / 2, x.x + W / 2, x.y + H / 2)
			, 0xFF0000);
	draw_line(mlx, ddddc(o.x + W / 2, o.y + H / 2, y.x + W / 2, y.y + H / 2)
			, 0x00FF00);
	draw_line(mlx, ddddc(o.x + W / 2, o.y + H / 2, z.x + W / 2, z.y + H / 2)
			, 0x0000FF);
}
