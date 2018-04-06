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
	t_vec4 m1x;
	t_vec4 m1y;
	t_vec4 m1z;
	t_vec4 m1w;

	m1x = vec4(m.x_axis.x, m.y_axis.x, m.z_axis.x, m.w_axis.x);
	m1y = vec4(m.x_axis.y, m.y_axis.y, m.z_axis.y, m.w_axis.y);
	m1z = vec4(m.x_axis.z, m.y_axis.z, m.z_axis.z, m.w_axis.z);
	m1w = vec4(m.x_axis.w, m.y_axis.w, m.z_axis.w, m.w_axis.w);

	r.x = dot_vec4(v, m1x);
	r.y = dot_vec4(v, m1y);
	r.z = dot_vec4(v, m1z);
	r.w = dot_vec4(v, m1w);
	return (r);
}
