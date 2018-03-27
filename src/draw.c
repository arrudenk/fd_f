/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                              :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:10:14 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/27 14:28:23 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
//TODO: 				1			2			3			4			5		6
void	draw_line(t_mlx *mlx, double x1, double y1, double x2, double y2, int color)
{
	if (fabs(y2-y1) < fabs(x2-x1))
		if (x1 < x2)
			draw_h(mlx, x1, y1, x2, y2, color);
		else
			draw_h(mlx, x2, y2, x1, y1, color);
	else
		if (y1 < y2)
			draw_v(mlx, x1, y1, x2, y2, color);
		else
			draw_v(mlx, x2, y2, x1, y1, color);
}
//																			6
void	draw_h(t_mlx *mlx, double x1, double y1, double x2, double y2, int color)
{
	double y;
	double startX;
	double endX;
/*	error = 0;
	delta_error = (fabs(x2-x1) / fabs(y2-y1));*/
	startX = x1;
	endX = x2;
	while (startX < endX)
	{
		y = ((y2 - y1)/(x2 - x1)) * (startX - x1) + y1;
		mlx_pixel_put(mlx->mlx, mlx->win, startX, y, color);
/*		error += delta_error;
		if (error >= 0.5)
		{
			y += direction_y;
			error--;
		}*/
		startX++;
	}
}
//																			6
void	draw_v(t_mlx *mlx, double x1, double y1, double x2, double y2, int color)
{
	double x;
	double startY;
	double endY;
//	double delta_error;
/*	double error;
	double direction_y;
	direction_y = (y2-y1) > 0 ? 1 : -1;
	error = 0;
	delta_error = fabs(x2-x1)/fabs(y2-y1);


	 Notice that we pass through Y coordinate
	 and calculate X with respect to it*/
	startY = y1;
	endY = y2;
	while (startY < endY)
	{
		x = ((x2 - x1)/(y2 - y1)) * (startY - y1) + x1;
		mlx_pixel_put(mlx->mlx, mlx->win, x, startY, color);
		startY++;
/*		error += delta_error;
		if (error >= 0.5)
		{
			y += direction_y;
			error--;
		}*/
	}
}

// Raw version of draw map, that just draws lines along X and Y
//TODO: make 25 lines func
void	draw_model(t_mlx* mlx, t_model *model)
{
	int i;
	int j;

	mlx_clear_window(mlx->mlx, mlx->win);
	i = -1;
	while (++i < model->size_x)
	{
		j = -1;
		while (++j < model->size_y - 1)
		{
			draw_line(mlx, M_X(i, j) + W / 2, M_Y(i, j) + H / 2
					, M_X(i, j + 1) + W / 2, M_Y(i, j + 1) + H / 2, VIOLET);
		}
	}
	i = -1;
	while (++i < model->size_y)
	{
		j = -1;
		while (++j < model->size_x - 1)
		{
			draw_line(mlx, M_X(j, i) + W/2, M_Y(j, i) + H/2
					, M_X(j + 1, i) + W/2, M_Y(j + 1, i) + H/2, VIOLET);
		}
	}
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
	draw_line(mlx, o.x + W/2, o.y + H/2, x.x + W/2, x.y + H/2, 0xFF0000);
	draw_line(mlx, o.x + W/2, o.y + H/2, y.x + W/2, y.y + H/2, 0x00FF00);
	draw_line(mlx, o.x + W/2, o.y + H/2, z.x + W/2, z.y + H/2, 0x0000FF);
}
