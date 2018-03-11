/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:10:14 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/07 13:10:28 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void 	draw_line(t_mlx *mlx, double x1, double y1
		, double x2, double y2, int color)
{
	if (fabs(y2-y1) < fabs(x2-x1))
	{
		if (x1 < x2)
		{
			draw_line_h(mlx, x1, y1, x2, y2, color);
		}
		else
		{
			draw_line_h(mlx, x2, y2, x1, y1, color);
		};
	}
	else
	{
		if (y1 < y2)
		{
			draw_line_v(mlx, x1, y1, x2, y2, color);

		}
		else
		{
			draw_line_v(mlx, x2, y2, x1, y1, color);
		};
	}
}

// draw line if it is horizontal
void draw_line_h(t_mlx *mlx, double x1, double y1, double x2, double y2, int color)
{
	double delta_x;
	double delta_y;
	double delta_error;
	double y;
	double error;
	double startX;
	double endX;
	double direction_y;

	error = 0;
	delta_x = fabs(x2-x1);
	delta_y = fabs(y2-y1);
	delta_error = delta_y/delta_x;

	direction_y = (y2-y1) > 0 ? 1 : -1;

	startX = x1;
	endX = x2;

	while (startX < endX)
	{
		y = ((y2 - y1)/(x2 - x1)) * (startX - x1) + y1;
		mlx_pixel_put(mlx->mlx, mlx->win, startX, y, color);

		error += delta_error;

		/*if (error >= 0.5)
		{
			y += direction_y;
			error--;
		}*/

		startX++;
	}
}

// Draw line if it is vertical
void draw_line_v(t_mlx *mlx, double x1, double y1, double x2, double y2, int color)
{
	double delta_x;
	double delta_y;
	double delta_error;
	double x;
	double error;
	double startY;
	double endY;
	double direction_y;

	error = 0;
	delta_x = fabs(x2-x1);
	delta_y = fabs(y2-y1);
	delta_error = delta_y/delta_x;

	direction_y = (y2-y1) > 0 ? 1 : -1;
	// Notice that we pass through Y coordinate
	// and calculate X with respect to it
	startY = y1;
	endY = y2;

	while (startY < endY)
	{
		x = ((x2 - x1)/(y2 - y1)) * (startY - y1) + x1;
		mlx_pixel_put(mlx->mlx, mlx->win, x, startY, color);

		error += delta_error;

		/*if (error >= 0.5)
		{
			y += direction_y;
			error--;
		}*/

		startY++;
	}
}

// Raw version of draw map, that just draws lines along X and Y
void draw_map(t_mlx* mlx, t_map *map)
{
	for (int i=0; i < map->size_x; i++)
	{
		for (int j=0; j < map->size_y-1; j++)
		{
			draw_line(mlx,
					  map->data[i][j]->x + WIDTH/2,
					  map->data[i][j]->y + HEIGHT/2,
					  map->data[i][j+1]->x + WIDTH/2,
					  map->data[i][j+1]->y + HEIGHT/2,
					  VIOLET);
		}
	}

	for (int k=0; k < map->size_y; k++)
	{
		for (int l=0; l < map->size_x-1; l++)
		{
			draw_line(mlx,
					  map->data[l][k]->x + WIDTH/2,
					  map->data[l][k]->y + HEIGHT/2,
					  map->data[l+1][k]->x + WIDTH/2,
					  map->data[l+1][k]->y + HEIGHT/2,
					  VIOLET);
		}
	}
}


