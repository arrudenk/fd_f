/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_tools.c                                       :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:20:11 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/27 18:44:04 by arrudenk         ###   ########.fr       */
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
	new_model = init_model();
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
	return (new_model);
}

t_model		*transform_model(t_mat4 *matrix, t_model *model)
{
	t_model	*new_model;
	int		i;
	int		j;

	i = -1;
	new_model = copy_model(model);
	new_model->data = ft_memalloc(sizeof(t_point *) * model->size_x);
	while (++i < model->size_x)
	{
		new_model->data[i] = ft_memalloc(sizeof(t_point *) * model->size_y);
		j = -1;
		while (++j < model->size_y)
		{
			new_model->data[i][j] = ft_memalloc(sizeof(t_point));
			new_model->data[i][j]->pos = vec4_mat4_multiply(POS(i, j), matrix);
		}
	}
	new_model->size_x = model->size_x;
	new_model->size_y = model->size_y;
	return (new_model);
}

t_model		*init_model(void)
{
	t_model *map;

	map = (t_model *)ft_memalloc(sizeof(t_model));
	return (map);
}

t_draw		ddddc(double x1, double y1, double x2, double y2)
{
	t_draw	info;

	info.x1 = x1;
	info.y1 = y1;
	info.x2 = x2;
	info.y2 = y2;
	return (info);
}
