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
	t_fdf		fdf;
	char		*file;

	file = "../maps/pyramid";
//	if (argc != 2)
//		error(1);
	model = init_model();
	fdf.cam = camera(vec3(0.5, 0.0, 0.0)
					, vec3(1.0, 0.0, 0.0)
					, vec3(0.0, 1.0, 0.0));
	get_model(model, file);
	fdf.model = transform_model(fdf.cam, model);
	fdf.mlx = init_mlx();
	fdf.colr = VIOLET;

	draw_model(fdf);
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
		(*fdf).model = x_rotate_key(key, fdf);
	}
	if (key == UP || key == DOWN || key == 65362 || key == 65364)
	{
		y_rotate_key(key, fdf);
	}
	if (key == MINUS || key == PLUS)
	{
		(*fdf).model = scale(fdf, key);
	}
	if (key == U_ZERO || key == U_ONE)
	{
//		z_height((*fdf), key);
//		(*fdf).model = transform_model(destroy_z(), (*fdf).model);
	}
	if (key == MAC_RANDOM || key == U_RANDOM)
	{
		if ((*fdf).colr == 1)
		{
			(*fdf).colr = VIOLET;
		}
		else
		{
			(*fdf).colr = 1;
		}
	}
	draw_model(*fdf);
	return (0);
}
