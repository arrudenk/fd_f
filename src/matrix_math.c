/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_math.c                                       :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:18:47 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/27 18:32:00 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector_math.h"

t_vec4		quick_math(t_vec4 axis, t_mat4 *m1, t_mat4 *m2)
{
	t_vec4 *m1x;
	t_vec4 *m1y;
	t_vec4 *m1z;
	t_vec4 *m1w;

	m1x = new_vec4(m1->x_axis.x, m1->y_axis.x, m1->z_axis.x, m1->w_axis.x);
	m1y = new_vec4(m1->x_axis.y, m1->y_axis.y, m1->z_axis.y, m1->w_axis.y);
	m1z = new_vec4(m1->x_axis.z, m1->y_axis.z, m1->z_axis.z, m1->w_axis.z);
	m1w = new_vec4(m1->x_axis.w, m1->y_axis.w, m1->z_axis.w, m1->w_axis.w);
	axis.x = dot_vec4(m1x, &m2->x_axis);
	axis.y = dot_vec4(m1y, &m2->x_axis);
	axis.z = dot_vec4(m1z, &m2->x_axis);
	axis.w = dot_vec4(m1w, &m2->x_axis);
	ft_memdel((void *)m1x);
	ft_memdel((void *)m1y);
	ft_memdel((void *)m1z);
	ft_memdel((void *)m1w);
	return (axis);
}

//TODO: del this or use

t_mat4		*mat4_mat4_multiply(t_mat4 *m1, t_mat4 *m2)
{
	t_mat4 *r;

	r = ft_memalloc(sizeof(t_mat4));
	r->x_axis = quick_math(r->x_axis, m1, m2);
	r->y_axis = quick_math(r->y_axis, m1, m2);
	r->z_axis = quick_math(r->z_axis, m1, m2);
	r->w_axis = quick_math(r->w_axis, m1, m2);
	return (r);
}
