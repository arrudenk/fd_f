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

void 	draw_line(t_mlx *map, double x1, double y1
		, double x2, double y2, int color)
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
	startX = (x2-x1) > 0 ? x1 : x2;
	endX = (x2-x1) > 0 ? x2 : x1;

	while (startX < endX)
	{
		mlx_pixel_put(map->mlx, map->win, startX, y, color);

		y = ((y2 - y1)/(x2 - x1)) * (startX - x1) + y1;
		error += delta_error;

		/*if (error >= 0.5)
		{
			y += direction_y;
			error--;
		}*/

		startX++;
	}
}

