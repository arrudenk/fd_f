/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 00:36:22 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/30 00:36:23 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	draw_h(t_mlx *mlx, t_draw i, int colr)
{
	double	y;
	double	start_x;
	double	end_y;

	start_x = i.x1;
	end_y = i.x2;
	if (colr == 1)
		colr = i.colr;
	while (start_x < end_y)
	{
		y = ((i.y2 - i.y1) / (i.x2 - i.x1)) * (start_x - i.x1) + i.y1;
		if (start_x > 0 && y > 0 && start_x < W && y < H)
			image_set_pixel(mlx, start_x, y, colr);
		else
			break ;
		start_x++;
	}
}

static void	draw_v(t_mlx *mlx, t_draw i, int colr)
{
	double	x;
	double	start_y;
	double	end_y;

	start_y = i.y1;
	end_y = i.y2;
	if (colr == 1)
		colr = i.colr;
	while (start_y < end_y)
	{
		x = ((i.x2 - i.x1) / (i.y2 - i.y1)) * (start_y - i.y1) + i.x1;
		if (start_y > 0 && x > 0 && start_y < H && x < W)
		{
			image_set_pixel(mlx, x, start_y, colr);
		}
		else
		{
			break ;
		}
		start_y++;
	}
}

static void	draw_line(t_mlx *mlx, t_draw info, int colr)
{
	if (fabs(info.y2 - info.y1) < fabs(info.x2 - info.x1))
	{
		if (info.x1 < info.x2)
			draw_h(mlx, double4(info.x1, info.y1, info.x2, info.y2), colr);
		else
			draw_h(mlx, double4(info.x2, info.y2, info.x1, info.y1), colr);
	}
	else
	{
		if (info.y1 < info.y2)
			draw_v(mlx, double4(info.x1, info.y1, info.x2, info.y2), colr);
		else
			draw_v(mlx, double4(info.x2, info.y2, info.x1, info.y1), colr);
	}
}

void		draw_model(t_fdf fdf)
{
	int i;
	int j;

	clear_image(fdf.mlx);
	i = -1;
	while (++i < fdf.model->size_x)
	{
		j = -1;
		while (++j < fdf.model->size_y - 1)
		{
			draw_line(fdf.mlx, double4(M_X(i, j) + W / 2, M_Y(i, j) + H / 2
					, M_X(i, j + 1) + W / 2, M_Y(i, j + 1) + H / 2), fdf.colr);
		}
	}
	i = -1;
	while (++i < fdf.model->size_y)
	{
		j = -1;
		while (++j < fdf.model->size_x - 1)
		{
			draw_line(fdf.mlx, double4(M_X(j, i) + W / 2, M_Y(j, i) + H / 2
					, M_X(j + 1, i) + W / 2, M_Y(j + 1, i) + H / 2), fdf.colr);
		}
	}
	mlx_put_image_to_window(fdf.mlx->mlx, fdf.mlx->win, FDIMG, 0, 0);
}
