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
	result = ft_memalloc(sizeof(t_mat4));

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

	return result;
}

t_vec3 normalize_vec3(t_vec3 v)
{
	/*t_vec3 *t;
	double l;

	t = ft_memalloc(sizeof(t_vec3));
	l = sqrt(v->x*v->x + v->x*v->x + )*/

}

// Hardcoded view matrix, gonna be replaced soon
t_mat4 *look_at() {
	t_mat4 *m;
	m = ft_memalloc(sizeof(t_mat4));

	m->x_axis = vec4(-0.948683, -0.0953463, 0.301511, 0);
	m->y_axis = vec4(0, 0.953463, 0.301511, 0);
	m->z_axis = vec4(-0.316228, 0.286039, -0.904534, 0);
	m->w_axis = vec4(0.316228, -0.286039, -0.753778, 1);

	return (m);
}

