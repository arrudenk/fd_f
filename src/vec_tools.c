/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 00:38:04 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/30 00:38:05 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector_math.h"

t_mat3		*new_mat3(void)
{
	t_mat3 *m;

	m = ft_memalloc(sizeof(t_mat3));
	m->x_axis = vec3(1, 0, 0);
	m->y_axis = vec3(0, 1, 0);
	m->z_axis = vec3(0, 0, 1);
	return (m);
}

t_mat4		new_mat4(void)
{
	t_mat4 m;

	m.x_axis = vec4(1, 0, 0, 0);
	m.y_axis = vec4(0, 1, 0, 0);
	m.z_axis = vec4(0, 0, 1, 0);
	m.w_axis = vec4(0, 0, 0, 1);
	return (m);
}

t_vec3		vec3_mat3_multiply(t_vec3 v, t_mat3 *m)
{
	t_vec3 r;

	r.x = dot_vec3(v, m->x_axis);
	r.y = dot_vec3(v, m->y_axis);
	r.z = dot_vec3(v, m->z_axis);
	return (r);
}

t_vec4		vec4_mat4_multiply(t_vec4 v, t_mat4 m)
{
	t_vec4 r;

	r.x = dot_vec4(v, m.x_axis);
	r.y = dot_vec4(v, m.y_axis);
	r.z = dot_vec4(v, m.z_axis);
	r.w = dot_vec4(v, m.w_axis);
	return (r);
}
