#include "../include/vector_math.h"

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
