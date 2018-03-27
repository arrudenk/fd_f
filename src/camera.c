/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:14:51 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/27 18:15:55 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector_math.h"

t_mat4	*look_at(t_vec3 *eye, t_vec3 *target, t_vec3 *up)
{
	t_mat4	*m;
	t_vec3	*f;
	t_vec3	*s;
	t_vec3	*u;

	m = ft_memalloc(sizeof(t_mat4));
	f = normalize_vec3(subtract_vec3(target, eye));
	s = normalize_vec3(cross_vec3(f, up));
	u = cross_vec3(s, f);
	m->x_axis = vec4(s->x, u->x, f->x, 0);
	m->y_axis = vec4(s->y, u->y, f->y, 0);
	m->z_axis = vec4(s->z, u->z, f->z, 0);
	m->w_axis = vec4(dot_vec3(s, eye), dot_vec3(u, eye)
			, dot_vec3(f, eye), 1);
	return (m);
}
