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

int		get_map(t_model *model, char *file)
{
	int		fd;
	int		fd2;
	size_t	x_size;
	size_t	y_size;
	char	*line;
	char	**cols;
	int		i;
	int		j;

	x_size = 0;
	y_size = 0;
	i = 0;
	fd2 = open(file, O_RDONLY);
	while (get_next_line(fd2, &line))
	{
		x_size++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	model->data = ft_memalloc(sizeof(t_point *) * x_size);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		j = 0;
		cols = ft_strsplit(line, ' ');
		while (cols[y_size])
		{
			y_size++;
		}
		model->data[i] = ft_memalloc(sizeof(t_point *) * y_size);
		while (cols[j])
		{
			double fetched_x = i * STEP;
			double fetched_y = j * STEP;
			double fetched_z = ft_atoi(cols[j]) * STEP;
			double fetched_w = 1;
			model->data[i][j] = ft_memalloc(sizeof(t_point));
			model->data[i][j]->rgb = new_color(cols[j]);
			model->data[i][j]->pos = new_vec4(fetched_x, fetched_z, fetched_y, fetched_w);
			j++;
		}
		i++;
	}
	model->size_x = x_size;
	model->size_y = y_size;
	return (1);
}

t_vec3	*new_color(char *point)
{
	t_vec3	*color;
	char	*col;
	char	*color_buff[3];
	int		i;

	i = -1;
	col = ft_strchr(point, 'x');					//find 'x' and back string shifted to "х"
	if (col == NULL)
	{
		color = new_vec3(0, 0, 0);
		return (color);
	}
	col++;
	while (++i < 3)
	{
		color_buff[i] =  ft_strnew(sizeof(char) * 2);
		ft_strncpy(color_buff[i], col, 2);				//man strncpy
		col +=2;
	}
	color = new_vec3(ft_atoi_hex(color_buff[0])
					, ft_atoi_hex(color_buff[1])
					, ft_atoi_hex(color_buff[2]));
	return (color);
}

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Hello MLX");
	return (mlx);
}

t_model	*init_model()
{
	t_model *map;

	map = (t_model *)ft_memalloc(sizeof(t_model));
	return map;
}
