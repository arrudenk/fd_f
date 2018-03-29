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
