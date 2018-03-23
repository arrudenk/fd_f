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
	t_vec3 *r;
	r = ft_memalloc(sizeof(t_mat3));

	r->x = dot_vec3(v, &m->x_axis);
	r->y = dot_vec3(v, &m->y_axis);
	r->z = dot_vec3(v, &m->z_axis);

	return r;
}

t_vec4		*vec4_mat4_multiply(t_vec4 *v, t_mat4* m)
{
	t_vec4 *r;
	r = ft_memalloc(sizeof(t_vec4));

	r->x = dot_vec4(v, &m->x_axis);
	r->y = dot_vec4(v, &m->y_axis);
	r->z = dot_vec4(v, &m->z_axis);
	r->w = dot_vec4(v, &m->w_axis);

	return (r);
}



t_mat4 *mat4_mat4_multiply(t_mat4* m1, t_mat4* m2)
{
	t_mat4 *r;
	t_vec4 *m1x;
	t_vec4 *m1y;
	t_vec4 *m1z;
	t_vec4 *m1w;

	ft_memalloc(sizeof(t_vec4 *) * 5);
	r = ft_memalloc(sizeof(t_mat4));
	m1x = new_vec4(m1->x_axis.x, m1->y_axis.x, m1->z_axis.x, m1->w_axis.x);
	m1y = new_vec4(m1->x_axis.y, m1->y_axis.y, m1->z_axis.y, m1->w_axis.y);
	m1z = new_vec4(m1->x_axis.z, m1->y_axis.z, m1->z_axis.z, m1->w_axis.z);
	m1w = new_vec4(m1->x_axis.w, m1->y_axis.w, m1->z_axis.w, m1->w_axis.w);

	r->x_axis.x = dot_vec4(m1x, &m2->x_axis);
	r->x_axis.y = dot_vec4(m1y, &m2->x_axis);
	r->x_axis.z = dot_vec4(m1z, &m2->x_axis);
	r->x_axis.w = dot_vec4(m1w, &m2->x_axis);

	r->y_axis.x = dot_vec4(m1x, &m2->y_axis);
	r->y_axis.y = dot_vec4(m1y, &m2->y_axis);
	r->y_axis.z = dot_vec4(m1z, &m2->y_axis);
	r->y_axis.w = dot_vec4(m1w, &m2->y_axis);

	r->z_axis.x = dot_vec4(m1x, &m2->z_axis);
	r->z_axis.y = dot_vec4(m1y, &m2->z_axis);
	r->z_axis.z = dot_vec4(m1z, &m2->z_axis);
	r->z_axis.w = dot_vec4(m1w, &m2->z_axis);

	r->w_axis.x = dot_vec4(m1x, &m2->w_axis);
	r->w_axis.y = dot_vec4(m1y, &m2->w_axis);
	r->w_axis.z = dot_vec4(m1z, &m2->w_axis);
	r->w_axis.w = dot_vec4(m1w, &m2->w_axis);

	return (r);
}

t_vec3 *normalize_vec3(t_vec3 *v)
{
	t_vec3	*r;
	double	l;

	r = ft_memalloc(sizeof(t_vec3));

	l = sqrt(v->x*v->x + v->y*v->y + v->z*v->z);

	r->x = v->x/l;
	r->y = v->y/l;
	r->z = v->z/l;

	return (r);
}

double dot_vec3(t_vec3 *v1, t_vec3 *v2)
{
	double r = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;

	return (r);
}

double dot_vec4(t_vec4 *v1, t_vec4 *v2)
{
	double r = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z + v1->w * v2->w;

	return (r);
}

t_vec3 *cross_vec3(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3 *r;
	r = ft_memalloc(sizeof(t_vec3));

	r->x = v1->y * v2->z - v2->y * v1->z;
	r->y = v1->x * v2->z - v2->x * v1->z;
	r->z = v1->x * v2->y - v2->x * v1->y;

	return (r);
}

t_vec3 *subtract_vec3(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3 *r;
	r = ft_memalloc(sizeof(t_vec3));

	r->x = v1->x - v2->x;
	r->y = v1->y - v2->y;
	r->z = v1->z - v2->z;

	return (r);
}

// Hardcoded view matrix, gonna be replaced soon
t_mat4 *look_at(t_vec3 *eye, t_vec3 *target, t_vec3 *up) {
	t_mat4 *m;
	m = ft_memalloc(sizeof(t_mat4));

	t_vec3 *f;
	t_vec3 *s;
	t_vec3 *u;

	double t_x;
	double t_y;
	double t_z;

	f = normalize_vec3(subtract_vec3(target, eye));
	s = normalize_vec3(cross_vec3(f, up));
	u = cross_vec3(s, f);

	t_x = dot_vec3(s, eye);
	t_y = dot_vec3(u, eye);
	t_z = dot_vec3(f, eye);

	m->x_axis = vec4(s->x, u->x, f->x, 0);
	m->y_axis = vec4(s->y, u->y, f->y, 0);
	m->z_axis = vec4(s->z, u->z, f->z, 0);
	m->w_axis = vec4(t_x, t_y, t_z, 1);

	return (m);
}


