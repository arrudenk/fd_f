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
	t_pixel	*pix;
	t_mlx	*mlx;
	t_mlx	*map;
	int		i;
	int 	x_size;

	i = 0;
	x_size = 0;
	mlx = init_mlx();
	fd = open("../maps/test1", O_RDONLY);

	while (get_next_line(fd, &line))
		x_size++;
	close(fd);
	ft_strdel(&line);
	t_pixel		**mapa;
	ft_memalloc(sizeof(t_pixel *) * x_size);
	while (get_next_line(fd, &line))
	{

	}

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

t_pixel		*new_pixel(char *map)
{
	t_pixel		*pixel;
	char		**split;
	int			i;

	i = -1;
	split = ft_strsplit(map, ' ');
	pixel = ft_memalloc(sizeof(t_pixel));
	pixel->x = ft_atoi(split[0]);
	pixel->y = ft_atoi(split[1]);
	while(split[++i])
		ft_strdel(&split[i]);
	free(split);
	ft_strdel(&map);
	return (pixel);
}

t_mlx		*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Hello MLX");
	return (mlx);
}