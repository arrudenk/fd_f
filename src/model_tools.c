/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 00:37:07 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/30 00:37:08 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		print_model(t_model *model)
{
	int i;
	int j;

	i = -1;
	while (++i < model->size_x)
	{
		j = -1;
		while (++j < model->size_y)
		{
			print_vec4(model->data[i][j]->pos);
		}
	}
}

t_model		*copy_model(t_model *src)
{
	t_model	*new_model;
	int		i;
	int		j;

	i = -1;
	new_model = (t_model *)ft_memalloc(sizeof(t_model));
	new_model->data = ft_memalloc(sizeof(t_point *) * src->size_x);
	while (++i < src->size_x)
	{
		j = -1;
		new_model->data[i] = ft_memalloc(sizeof(t_point *) * src->size_y);
		while (++j < src->size_y)
		{
			new_model->data[i][j] = ft_memalloc(sizeof(t_point));
			ft_memcpy((void*)new_model->data[i][j], (void*)src->data[i][j]
					, sizeof(t_point));
		}
	}
	new_model->size_x = src->size_x;
	new_model->size_y = src->size_y;
	return (new_model);
}

t_model		*transform_model(t_mat4 matrix, t_model *model)
{
	int		i;
	int		j;

	i = -1;
	while (++i < model->size_x)
	{
		j = -1;
		while (++j < model->size_y)
		{
			model->data[i][j]->pos = vec4_mat4_multiply(POS(i, j), matrix);
		}
	}
//	print_model(model);
	return (model);
}

t_model		*init_model(void)
{
	t_model *map;

	map = (t_model *)ft_memalloc(sizeof(t_model));
	return (map);
}

t_draw		double4(double x1, double y1, double x2, double y2)
{
	t_draw	info;

	info.x1 = x1;
	info.y1 = y1;
	info.x2 = x2;
	info.y2 = y2;
	return (info);
}
