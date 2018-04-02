/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 14:32:44 by arrudenk          #+#    #+#             */
/*   Updated: 2018/04/02 14:32:45 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static t_model	*zoomer(t_model *fdf)
{
	t_mat4	r;

	r = new_mat4();
	r.x_axis.x = 1.8;
	r.y_axis.y =  1.8;
	r.z_axis.z = 1.8;
	r.w_axis.w = 1;


	return (transform_model(r, fdf));
}

static t_model	*zoom_out(t_model *fdf)
{
	t_mat4	r;

	r = new_mat4();

	r.x_axis.x = 0.8;
	r.y_axis.y =  0.8;
	r.z_axis.z = 0.8;
	r.w_axis.w = 1;


	return (transform_model(r, fdf));
}

t_model			*scale(t_fdf *fdf, int key)
{
	if (key == PLUS)
		return (zoomer((*fdf).model));
	else
		return (zoom_out((*fdf).model));
}