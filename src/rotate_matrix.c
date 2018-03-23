//
// Created by stefan on 3/23/18.
//

#include "../include/vector_math.h"

t_mat4 *create_x_rotation(double mod)
{
	t_mat4 *r;

	r = ft_memalloc(sizeof(t_mat4));

	r->x_axis = vec4(1, 0, 0, 0);
	r->y_axis = vec4(0, cos(mod * ANGLE * RAD), -sin(mod * ANGLE * RAD), 0);
	r->z_axis = vec4(0, sin(mod * ANGLE * RAD), cos(mod * ANGLE * RAD), 0);
	r->w_axis = vec4(0, 0, 0, 1);

	return (r);
}

t_mat4 *create_y_rotation(double mod)
{
	t_mat4 *r;

	r = ft_memalloc(sizeof(t_mat4));

	r->x_axis = vec4(cos(SINCOS), 0, sin(SINCOS), 0);
	r->y_axis = vec4(0, 1, 0, 0);
	r->z_axis = vec4(-sin(SINCOS), 0, cos(SINCOS), 0);
	r->w_axis = vec4(0, 0, 0, 1);

	return (r);
}

t_mat4 *create_z_rotation(double mod)
{
	t_mat4 *r;

	r = ft_memalloc(sizeof(t_mat4));

	r->x_axis = vec4(cos(SINCOS), -sin(SINCOS), 0, 0);
	r->y_axis = vec4(sin(SINCOS), cos(SINCOS), 0, 0);
	r->z_axis = vec4(0, 0, 1, 0);
	r->w_axis = vec4(0, 0, 0, 1);

	return (r);
}