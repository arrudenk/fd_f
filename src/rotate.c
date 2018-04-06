/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 00:37:38 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/30 00:37:39 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector_math.h"
#include "../include/fdf.h"

t_model		*x_rotate_key(int key, t_fdf *fdf)
{
	t_model	*model;
	t_model	*original;
	double	x;
	double	y;

	original = (*fdf).origin_model;
	x = original->data[original->size_x / 2][original->size_x / 2]->pos.x;
	y = original->data[original->size_x / 2][original->size_x / 2]->pos.y;
	ft_free_model((*fdf).model);
	if (key == RIGHT || key == 65363)
	{
		model = copy_model(transform_model(create_translation(vec3(x, y, 0))
				, transform_model(create_x_rotation(1)
						, transform_model(create_translation(vec3(-x, -y, 0))
								, original))));
		model = transform_model((*fdf).cam, model);
		return (model);
	}
	else
	{
		model = copy_model(transform_model(create_translation(vec3(x, y, 0))
				, transform_model(create_x_rotation(-1)
						, transform_model(create_translation(vec3(-x, -y, 0))
								, original))));
		model = transform_model((*fdf).cam, model);
		return (model);
	}
}

t_model		*z_rotate_key(int key, t_fdf *fdf)
{
	t_model *model;
	t_model *original;
	double	x;
	double	y;

	original = (*fdf).origin_model;
	x = original->data[original->size_x / 2][original->size_x / 2]->pos.x;
	y = original->data[original->size_x / 2][original->size_x / 2]->pos.y;
	ft_free_model((*fdf).model);
	if (key == Q)
	{
		model = copy_model(transform_model(create_translation(vec3(x, y, 0))
				, transform_model(create_z_rotation(1)
						, transform_model(create_translation(vec3(-x, -y, 0))
								, original))));
		return (transform_model((*fdf).cam, model));
	}
	else
	{
		model = copy_model(transform_model(create_translation(vec3(x, y, 0))
				, transform_model(create_z_rotation(-1)
						, transform_model(create_translation(vec3(-x, -y, 0))
								, original))));
		return (transform_model((*fdf).cam, model));
	}
}

t_model		*y_rotate_key(int key, t_fdf *fdf)
{
	t_model	*model;
	t_model	*original;
	double	x;
	double	y;

	original = (*fdf).origin_model;
	x = original->data[original->size_x / 2][original->size_x / 2]->pos.x;
	y = original->data[original->size_x / 2][original->size_x / 2]->pos.y;
	ft_free_model((*fdf).model);
	if (key == UP || key == 65362)
	{
		model = copy_model(transform_model(create_translation(vec3(x, y, 0))
				, transform_model(create_y_rotation(1)
						, transform_model(create_translation(vec3(-x, -y, 0))
								, original))));
		return (transform_model((*fdf).cam, model));
	}
	else
	{
		model = copy_model(transform_model(create_translation(vec3(x, y, 0))
				, transform_model(create_z_rotation(-1)
						, transform_model(create_translation(vec3(-x, -y, 0))
								, original))));
		return (transform_model((*fdf).cam, model));
	}
}
