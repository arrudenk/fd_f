/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_model.c                                      :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:04:27 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/26 21:09:01 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

size_t	get_xsize(int fd2)
{
	char	*line;
	size_t	x_size;

	x_size = 0;
	while (get_next_line(fd2, &line))
	{
		x_size++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (x_size);
}

void	push_data(t_model *model, char **data, int i)
{
	int j;

	j = 0;
	while (data[j])
	{
		model->data[i][j] = ft_memalloc(sizeof(t_point));
		model->data[i][j]->rgb = new_color(data[j]);
		model->data[i][j]->pos = new_vec4(i * STEP, j * STEP
				, ft_atoi(data[j]) * STEP, 1);
		j++;
	}
}

size_t	cols_num(char **cols)
{
	size_t	len;

	len = 0;
	while (cols[len])
		len++;
	return (len);
}

int		get_model(t_model *model, char *file)
{
	int		fd;
	int		fd2;
	char	*line;
	char	**cols;
	int		i;

	i = 0;
	fd2 = open(file, O_RDONLY);
	model->size_x = get_xsize(fd2);
	model->data = ft_memalloc(sizeof(t_point *) * model->size_x);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		cols = ft_strsplit(line, ' ');
		model->size_y = cols_num(cols);
		model->data[i] = ft_memalloc(sizeof(t_point *) * model->size_y);
		push_data(model, cols, i);
		i++;
	}
	model->size_y = cols_num(cols);
	return (1);
}
