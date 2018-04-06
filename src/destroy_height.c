/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_height.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:39:40 by arrudenk          #+#    #+#             */
/*   Updated: 2018/04/04 14:39:42 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by garry-umbrella on 30.03.18.
//

#include "../include/fdf.h"


//t_mat4		destroy_z()
//{
//	t_mat4	destroy_z;
//
//	destroy_z = new_mat4();
//	destroy_z.x_axis = vec4(1, 0, 0, 0);
//	destroy_z.y_axis = vec4(0, 0.5, 0, 0);
//	destroy_z.z_axis = vec4(0, 0, 1, 0);
//	destroy_z.w_axis = vec4(0, 0, 0, 1);
//
//	return (destroy_z);
//}
//
//static void	worker(t_fdf fdf)
//{
//	fdf.model = transform_model(destroy_z(), fdf.model);
//	draw_model(fdf);
//}
//
//void		z_height(t_fdf fdf, int key)
//{
//	if (key == U_ZERO)
//		worker(fdf);
//	else
//		worker(fdf);
//}
