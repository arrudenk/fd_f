/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 00:35:43 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/30 00:35:45 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_vec3	new_color(char *point)
{
	t_vec3	color;
	char	*col;
	char	*color_buff[3];
	int		i;

	i = -1;
	col = ft_strchr(point, 'x');
	if (col == NULL)
	{
		color = vec3(0, 0, 0);
		return (color);
	}
	col++;
	while (++i < 3)
	{
		color_buff[i] = ft_strnew(sizeof(char) * 2);
		ft_strncpy(color_buff[i], col, 2);
		col += 2;
	}
	color = vec3(ft_atoi_hex(color_buff[0])
			, ft_atoi_hex(color_buff[1])
			, ft_atoi_hex(color_buff[2]));
	return (color);
}
