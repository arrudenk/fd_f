/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                       :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:09:44 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/22 11:23:48 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector_math.h"

t_vec3		*new_vec3(double x, double y, double z)
{
	t_vec3		*v;
	v = ft_memalloc(sizeof(t_vec3));

	v->x = x;
	v->y = y;
	v->z = z;

	return (v);
}

t_vec4		*new_vec4(double x, double y, double z, double w)
{
	t_vec4		*v;
	v = ft_memalloc(sizeof(t_vec4));

	v->x = x;
	v->y = y;
	v->z = z;
	v->w = w;

	return (v);
}

t_vec3		vec3(double x, double y, double z)
{
	t_vec3		v;

	v.x = x;
	v.y = y;
	v.z = z;

	return (v);
}

t_vec4		vec4(double x, double y, double z, double w)
{
	t_vec4		v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = w;

	return (v);
}

t_mat3		*new_mat3()
{
	t_mat3 *m;
	m = ft_memalloc(sizeof(t_mat3));

	m->x_axis = vec3(1, 0, 0);
	m->y_axis = vec3(0, 1, 0);
	m->z_axis = vec3(0, 0, 1);

	return (m);
}

t_mat4		*new_mat4()
{
	t_mat4 *m;
	m = ft_memalloc(sizeof(t_mat4));

	m->x_axis = vec4(1, 0, 0, 0);
	m->y_axis = vec4(0, 1, 0, 0);
	m->z_axis = vec4(0, 0, 1, 0);
	m->w_axis = vec4(0, 0, 0, 1);

	return (m);
}

t_vec3		*vec3_mat3_multiply(t_vec3 *v, t_mat3* m)
{
	t_vec3 *result;
	result = ft_memalloc(sizeof(t_mat3));

	result->x = v->x * m->x_axis.x +
			   v->y * m->y_axis.x +
			   v->z * m->z_axis.x;

	result->y = v->x * m->x_axis.y +
			   v->y * m->y_axis.y +
			   v->z * m->z_axis.y;

	result->z = v->x * m->x_axis.z +
			   v->y * m->y_axis.z +
			   v->z * m->z_axis.z;

	return result;
}

t_vec4		*vec4_mat4_multiply(t_vec4 *v, t_mat4* m)
{
	t_vec4 *result;
	result = ft_memalloc(sizeof(t_vec4));

	result->x = v->x * m->x_axis.x +
				v->y * m->y_axis.x +
				v->z * m->z_axis.x +
				v->w * m->w_axis.x;

	result->y = v->x * m->x_axis.y +
				v->y * m->y_axis.y +
				v->z * m->z_axis.y +
				v->w * m->w_axis.y;

	result->z = v->x * m->x_axis.z +
				v->y * m->y_axis.z +
				v->z * m->z_axis.z +
				v->w * m->w_axis.z;

	result->w = v->x * m->x_axis.w +
				v->y * m->y_axis.w +
				v->z * m->z_axis.w +
				v->w * m->w_axis.w;

	return (result);
}

t_vec3 normalize_vec3(t_vec3 v)
{
	t_vec3 t;
	double l;

	//t = ft_memalloc(sizeof(t_vec3));
	l = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);

	t.x = v.x/l;
	t.y = v.y/l;
	t.z = v.z/l;

	return (t);
}

double dot_vec3(t_vec3 v1, t_vec3 v2)
{
	double r = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;

	return (r);
}

t_vec3 cross_vec3(t_vec3 v1, t_vec3 v2)
{
	t_vec3 r;

	r.x = v1.y * v2.z - v2.y * v1.z;
	r.y = v1.x * v2.z - v2.x * v1.z;
	r.z = v1.x * v2.y - v2.x * v1.y;

	return (r);
}

t_vec3 subtract_vec3(t_vec3 v1, t_vec3 v2)
{
	t_vec3 r;

	r.x = v1.x - v2.x;
	r.y = v1.y - v2.y;
	r.z = v1.z - v2.z;

	return (r);
}

// Hardcoded view matrix, gonna be replaced soon
t_mat4 *look_at(t_vec3 eye, t_vec3 target, t_vec3 up) {
	t_mat4 *m;
	m = ft_memalloc(sizeof(t_mat4));

	t_vec3 f;
	t_vec3 s;
	t_vec3 u;

	double t_x;
	double t_y;
	double t_z;

	f = normalize_vec3(subtract_vec3(target, eye));
	s = normalize_vec3(cross_vec3(f, up));
	u = cross_vec3(s, f);

	t_x = dot_vec3(s, eye);
	t_y = dot_vec3(u, eye);
	t_z = dot_vec3(f, eye);

	m->x_axis = vec4(s.x, u.x, f.x, 0);
	m->y_axis = vec4(s.y, u.y, f.y, 0);
	m->z_axis = vec4(s.z, u.z, f.z, 0);
	m->w_axis = vec4(t_x, t_y, t_z, 1);

	return (m);
}

