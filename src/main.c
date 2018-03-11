/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:01:25 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/07 13:01:27 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_vec3	*pix;
	t_mlx	*mlx;
	t_map	*map;
	int		i;
	int		j;
	int		x_size;
	int		y_size;
	t_vec4		***mapa;
	char		**cols;

	i = 0;
	x_size = 0;
	y_size = 0;
	mlx = init_mlx();
	map = init_map();
	fd = open("../maps/test1", O_RDONLY);

	while (get_next_line(fd, &line))
	{
		x_size++;
	}
	close(fd);
	ft_strdel(&line);
	map->data = ft_memalloc(sizeof(t_vec4 *) * x_size);
	fd = open("../maps/test1copy", O_RDONLY);
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

			map->data[i][j] = new_vec4(fetched_x, -fetched_z, fetched_y, fetched_w);
			j++;
		}
		i++;
	}
	map->size_x = x_size;
	map->size_y = y_size;
	// ############ MAP INITIALIZATION #############


	t_mat4 *test_view = look_at();
	t_map *trans_map = transform_map(test_view, map);
	print_map(trans_map);

	draw_map(mlx, trans_map);
	mlx_key_hook(mlx->win, hook_keydown, NULL);
	mlx_loop(mlx->mlx);
	return (0);
}

void		read_map()
{

}

int			hook_keydown(int key)
{
	if (key == 65307 || key == 53)
		exit(1);
	return (0);
}

t_mlx		*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Hello MLX");
	return (mlx);
}

t_map		*init_map()
{
	t_map *map;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	return map;
}

void		print_vec3(t_vec3 *v)
{
	ft_putstr("vec3: ");
	ft_putnbr(v->x);
	ft_putstr(", ");
	ft_putnbr(v->y);
	ft_putstr(", ");
	ft_putnbr(v->z);
	ft_putchar('\n');
}

void		print_vec4(t_vec4 *v)
{
	ft_putstr("vec4: ");
	ft_putnbr(v->x);
	ft_putstr(", ");
	ft_putnbr(v->y);
	ft_putstr(", ");
	ft_putnbr(v->z);
	ft_putstr(", ");
	ft_putnbr(v->w);
	ft_putchar('\n');
}

void		print_map(t_map *map)
{
	for (int i=0; i < map->size_x; i++)
	{
		for (int j=0; j < map->size_y; j++)
		{
			print_vec4(map->data[i][j]);
		}
	}
}

t_map		*transform_map(t_mat4 *matrix, t_map *map)
{
	t_map *transformed_map;
	transformed_map = init_map();

	transformed_map->data = ft_memalloc(sizeof(t_vec4 *) * map->size_x);
	for (int i=0; i < map->size_x; i++)
	{
		transformed_map->data[i] = ft_memalloc(sizeof(t_vec4 *) * map->size_y);
		for (int j=0; j < map->size_y; j++)
		{
			transformed_map->data[i][j] = vec4_mat4_multiply(map->data[i][j], matrix);
		}
	}

	transformed_map->size_x = map->size_x;
	transformed_map->size_y = map->size_y;

	return (transformed_map);
}