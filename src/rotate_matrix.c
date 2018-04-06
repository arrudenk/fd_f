/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 00:37:34 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/30 00:37:35 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector_math.h"
#include "../include/fdf.h"

t_mat4	create_x_rotation(double mod)
{
	t_mat4 r;

	r.x_axis = vec4(1, 0, 0, 0);
	r.y_axis = vec4(0, cos(mod * RAD), -sin(mod * RAD), 0);
	r.z_axis = vec4(0, sin(mod * RAD), cos(mod * RAD), 0);
	r.w_axis = vec4(0, 0, 0, 1);
	return (r);
}

t_mat4	create_y_rotation(double mod)
{
	t_mat4	r;

	r.x_axis = vec4(cos(mod * RAD), 0, sin(mod * RAD), 0);
	r.y_axis = vec4(0, 1, 0, 0);
	r.z_axis = vec4(-sin(mod * RAD), 0, cos(mod * RAD), 0);
	r.w_axis = vec4(0, 0, 0, 1);
	return (r);
}

t_mat4	create_z_rotation(double mod)
{
	t_mat4	r;

	r.x_axis = vec4(cos(mod * RAD), -sin(mod * RAD), 0, 0);
	r.y_axis = vec4(sin(mod * RAD), cos(mod * RAD), 0, 0);
	r.z_axis = vec4(0, 0, 1, 0);
	r.w_axis = vec4(0, 0, 0, 1);
	return (r);
}

t_mat4	create_translation(t_vec3 pos)
{
	t_mat4	r;

	r.x_axis = vec4(1.0, 0.0, 0.0, 0.0);
	r.y_axis = vec4(0.0, 1.0, 0.0, 0.0);
	r.z_axis = vec4(0.0, 0.0, 1.0, 0.0);
	r.w_axis = vec4(pos.x, pos.y, pos.z, 1.0);

	return (r);
}
