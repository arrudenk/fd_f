/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_matrix.c                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 21:55:10 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/27 19:10:55 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector_math.h"

//TODO: del this or use

t_mat4	*create_x_rotation(double mod)
{
	t_mat4	*r;

	r = ft_memalloc(sizeof(t_mat4));
	r->x_axis = vec4(1, 0, 0, 0);
	r->y_axis = vec4(0, cos(mod * RAD), -sin(mod * RAD), 0);
	r->z_axis = vec4(0, sin(mod * RAD), cos(mod * RAD), 0);
	r->w_axis = vec4(0, 0, 0, 1);
	return (r);
}

//TODO: del this or use

t_mat4	*create_y_rotation(double mod)
{
	t_mat4	*r;

	r = ft_memalloc(sizeof(t_mat4));
	r->x_axis = vec4(cos(mod * RAD), 0, sin(mod * RAD), 0);
	r->y_axis = vec4(0, 1, 0, 0);
	r->z_axis = vec4(-sin(mod * RAD), 0, cos(mod * RAD), 0);
	r->w_axis = vec4(0, 0, 0, 1);
	return (r);
}

//TODO: del this or use

t_mat4	*create_z_rotation(double mod)
{
	t_mat4	*r;

	r = ft_memalloc(sizeof(t_mat4));
	r->x_axis = vec4(cos(mod * RAD), -sin(mod * RAD), 0, 0);
	r->y_axis = vec4(sin(mod * RAD), cos(mod * RAD), 0, 0);
	r->z_axis = vec4(0, 0, 1, 0);
	r->w_axis = vec4(0, 0, 0, 1);
	return (r);
}
