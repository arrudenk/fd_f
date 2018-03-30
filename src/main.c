/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 00:36:40 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/30 00:36:41 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		error(int error)
{
	if (error == 1)
		ft_putendl("bad arguments");
	if (error == 2)
		ft_putendl("invalid map");
	if (error == 3)
		ft_putendl("");
	if (error == 4)
		ft_putendl("");
	if (error == 5)
		ft_putendl("");
	exit(error);
}

int			main(int argc, char **argv)
{
	t_model		*model;
	t_mat4		*rotation_mat;
	t_model		*trans_model;
	t_fdf		fdf;

	if (argc != 2)
		error(1);
	model = init_model();
	fdf.cam = camera(vec3(0.5, 0.0, 0.0)
					, vec3(1.0, 0.0, 0.0)
					, vec3(0.0, 1.0, 0.0));
	get_model(model, argv[1]);
	rotation_mat = create_x_rotation(60);
	trans_model = transform_model(rotation_mat, model);
	fdf.model = transform_model(fdf.cam, trans_model);
	fdf.mlx = init_mlx();

	draw_model(fdf.mlx, fdf.model);
	mlx_hook(fdf.mlx->win,2,5, hook_keydown, &fdf);
	mlx_loop(fdf.mlx->mlx);
	return (0);
}

int			hook_keydown(int key, t_fdf *fdf)
{
	if (key == 65307 || key == 53)
	{
		exit(1);
	}
	if (key == LEFT || key == RIGHT || key == 65363 || key == 65361)
	{
		x_rotate_key(key, fdf);
	}
	if (key == UP || key == DOWN)
	{
		y_rotate_key(key, fdf);
	}
	if (key == MINUS || key == PLUS)
	{
		z_rotate_key(key, fdf);
	}
	return (0);
}
