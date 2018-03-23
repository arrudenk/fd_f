//
// Created by stefan on 3/23/18.
//

#include "../include/vector_math.h"

t_mat4 *create_x_rotation(double angle)
{
	t_mat4 *r;

	r = ft_memalloc(sizeof(t_mat4));

	r->x_axis = vec4(1, 0, 0, 0);
	r->y_axis = vec4(0, cos(angle * RAD), -sin(angle * RAD), 0);
	r->z_axis = vec4(0, sin(angle * RAD), cos(angle * RAD), 0);
	r->w_axis = vec4(0, 0, 0, 1);

	return (r);
}

t_mat4 *create_y_rotation(double angle)
{
	t_mat4 *r;

	r = ft_memalloc(sizeof(t_mat4));

	r->x_axis = vec4(cos(angle * RAD), 0, sin(angle * RAD), 0);
	r->y_axis = vec4(0, 1, 0, 0);
	r->z_axis = vec4(-sin(angle * RAD), 0, cos(angle * RAD), 0);
	r->w_axis = vec4(0, 0, 0, 1);

	return (r);
}

t_mat4 *create_z_rotation(double angle)
{
	t_mat4 *r;

	r = ft_memalloc(sizeof(t_mat4));

	r->x_axis = vec4(cos(angle * RAD), -sin(angle * RAD), 0, 0);
	r->y_axis = vec4(sin(angle * RAD), cos(angle * RAD), 0, 0);
	r->z_axis = vec4(0, 0, 1, 0);
	r->w_axis = vec4(0, 0, 0, 1);

	return (r);
}