/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 18:21:15 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/29 18:21:16 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_mat4		look_at(t_vec3 eye, t_vec3 target, t_vec3 up)
{
	t_mat4	r;
	t_mat4	m;
	t_vec3	f;
	t_vec3	s;
	t_vec3	u;

	f = normalize_vec3(subtract_vec3(target, eye));
	s = normalize_vec3(cross_vec3(f, up));
	u = cross_vec3(s, f);
	m.x_axis = vec4(s.x, s.y, s.z, 0);
	m.y_axis = vec4(u.x, u.y, u.z, 0);
	m.z_axis = vec4(f.x, f.y, f.z, 0);
	m.w_axis = vec4(0, 0, 0, 1);
	r.x_axis = vec4(1, 0, 0, 0);
	r.y_axis = vec4(0, 1, 0, 0);
	r.z_axis = vec4(0, 0, 1, 0);
	r.w_axis = vec4(-eye.x, -eye.y, -eye.z, 1);
	return (mat4_mat4_multiply(r, m));
}

t_mat4		camera(t_vec3 eye, t_vec3 tar, t_vec3 up)
{
	t_mat4	cam;

	cam = look_at(eye, tar, up);
	return (cam);
}
