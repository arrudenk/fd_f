/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:04:27 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/18 16:04:27 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		fl_parther(t_map *map)
{
	int		fd;
	size_t	x_size;
	size_t	y_size;
	char	*line;
	char	**cols;
	int		i;
	int		j;

	x_size = 0;
	y_size = 0;
	i = 0;
	j = 0;
	fd = open("../maps/test2", O_RDONLY);
	while (get_next_line(fd, &line))
		x_size++;
	close(fd);
	fd = NULL;
	ft_strdel(&line);
	map->data = ft_memalloc(sizeof(t_vec4 *) * x_size);
	fd = open("../maps/test2", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		j = 0;

		cols = ft_strsplit(line, ' ');
		while (cols[y_size])
			y_size++;
		map->data[i] = ft_memalloc(sizeof(t_vec4 *) * y_size);
		while (cols[j])
		{
			double fetched_x = i * STEP;
			double fetched_y = j * STEP;
			double fetched_z = ft_atoi(cols[j]);
			double fetched_w = 1;

			map	->data[i][j] = new_vec4(fetched_x, fetched_z, fetched_y, fetched_w);
			j++;
		}
		i++;
	}
	map->size_x = x_size;
	map->size_y = y_size;
	return (1);
}

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Hello MLX");
	return (mlx);
}

t_map	*init_map()
{
	t_map *map;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	return map;
}
