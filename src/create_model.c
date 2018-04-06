/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_model.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 00:36:13 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/30 00:36:14 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int		get_xsize(int fd2)
{
	char	*line;
	int		x_size;

	x_size = 0;
	while (get_next_line(fd2, &line))
	{
		x_size++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (x_size);
}

static void		push_data(t_model *model, char **data, int i)
{
	int	j;

	j = -1;
	while (data[++j])
	{
		check_point(data[j]);
		model->data[i][j] = ft_memalloc(sizeof(t_point));
		model->data[i][j]->pos = vec4(i * STEP, j * STEP
				, ft_atoi(data[j]) * STEP, 1);
	}
}

static int		cols_num(char **cols)
{
	int	len;

	len = 0;
	while (cols[len])
		len++;
	return (len);
}

int				get_model(t_model *model, char *file)
{
	int		fd;
	int		fd2;
	char	*line;
	char	***cols;
	int		i;

	i = 0;
	fd2 = open(file, O_RDONLY);
	model->size_x = get_xsize(fd2);
	cols = ft_memalloc(sizeof(char **) * model->size_x + 10);
	model->data = ft_memalloc(sizeof(t_point *) * model->size_x);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		cols[i] = ft_strsplit(line, ' ');
		ft_strdel(&line);
		if (cols_num(cols[0]) != cols_num(cols[i]))
			error(6);
		model->size_y = cols_num(cols[i]);
		model->data[i] = ft_memalloc(sizeof(t_point *) * model->size_y);
		push_data(model, cols[i], i);
		i++;
	}
	ft_strdel(&line);
	ft_free_3d(cols);
	return (1);
}
