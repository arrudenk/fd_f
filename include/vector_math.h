//
// Created by vovchik on 09.03.18.
//

#ifndef FD_F_MATH_H
#define FD_F_MATH_H

#include "libft.h"
# include <math.h>

typedef struct	s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

typedef struct	s_vec4
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_vec4;

typedef struct	s_mat3
{
	t_vec3 x_axis;
	t_vec3 y_axis;
	t_vec3 z_axis;
}				t_mat3;

typedef struct	s_mat4
{
	t_vec4 x_axis;
	t_vec4 y_axis;
	t_vec4 z_axis;
	t_vec4 w_axis;
}				t_mat4;

t_vec3			*new_vec3(double x, double y, double z);
t_vec4			*new_vec4(double x, double y, double z, double w);
t_vec3			vec3(double x, double y, double z);
t_vec4			vec4(double x, double y, double z, double w);
double			dot_vec3(t_vec3 v1, t_vec3 v2);
t_vec3			cross_vec3(t_vec3 v1, t_vec3 v2);
t_vec3			*vector_matrix_product(t_vec3 *v, t_mat3* m);
t_vec3			subtract_vec3(t_vec3 v1, t_vec3 v2);
t_mat3			*new_mat3();
t_mat4			*new_mat4();
t_mat4			*look_at(t_vec3 eye, t_vec3 target, t_vec3 up);
t_vec3			normalize_vec3(t_vec3 v);


t_vec3			*vec3_mat3_multiply(t_vec3 *v, t_mat3* m);
t_vec4			*vec4_mat4_multiply(t_vec4 *v, t_mat4* m);

#endif //FD_F_MATH_H
