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
	if (key == RIGHT || key == 65363)
		return (transform_model(create_x_rotation(1), (*fdf).model));
	else
		return (transform_model(create_x_rotation(-1), (*fdf).model));
}

t_model		*z_rotate_key(int key, t_fdf *fdf)
{
	if (key == PLUS)
		return (transform_model(create_z_rotation(1), (*fdf).model));
	else
		return (transform_model(create_z_rotation(-1), (*fdf).model));
}

t_model		*y_rotate_key(int key, t_fdf *fdf)
{
	if (key == UP || key == 65362)
	{
		return (transform_model(create_y_rotation(1), (*fdf).model));
	}
	else
		return (transform_model(create_y_rotation(-1), (*fdf).model));
}
