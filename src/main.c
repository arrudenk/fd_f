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
	int		j;
	int		x_size;
	int		y_size;
	t_pixel		***mapa;
	char		**cols;

	i = 0;
	x_size = 0;
	y_size = 0;
	mlx = init_mlx();
	fd = open("../maps/test1", O_RDONLY);

	while (get_next_line(fd, &line))
	{
		x_size++;
	}
	close(fd);
	ft_strdel(&line);
	mapa = ft_memalloc(sizeof(t_pixel *) * x_size);
	fd = open("../maps/test1copy", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		j = 0;
		ft_putstr(line);
		cols = ft_strsplit(line, ' ');
		while (cols[y_size])
			y_size++;
		mapa[i] = ft_memalloc(sizeof(t_pixel *) * y_size);
		while (cols[j])
		{
			mapa[i][j] = new_pixel(cols[j], i, j);
			j++;
		}
		i++;
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

t_pixel		*new_pixel(char *pix, int x, int y)
{
	t_pixel		*pixel;

	pixel = ft_memalloc(sizeof(t_pixel));
	pixel->x = x * 8;
	pixel->y = y * 8;
	pixel->z = ft_atoi(pix);
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