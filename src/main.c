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
	if (error == -1)
		ft_putendl("bad argument");
	if (error == 2)
		ft_putendl("invalid map");
	if (error == 3)
		ft_putendl("");
	if (error == 4)
		ft_putendl("");
	if (error == 5)
		ft_putendl("");
	if (error == 6)
		ft_putendl("wrong map size");
	if (error == 7)
		ft_putendl("bad map char");
	exit(error);
}

int			main(int argc, char **argv)
{
//	ft_putstr("NUCLEAR POLYGON BITCH\n\n");
//
//	t_vec4 v1 = vec4(-3, 4, 1, 0);
//	t_vec4 v2 = vec4(-3, 4, 1, 0);
//	t_vec4 nv1 = normalize_vec4(v1);
//	t_vec4 nv2 = normalize_vec4(v2);
//
//	double d = dot_vec4(nv1, nv2);
//
//	t_mat4 mat1 = new_mat4();
//	mat1.x_axis = vec4(5, 1, 2, 0);
//	mat1.y_axis = vec4(-3, 2, 0, 1);
//	mat1.z_axis = vec4(0, 2, 4, 0);
//	mat1.w_axis = vec4(-6, 0, 1, 1);
//	print_mat4(mat1);
//
//	t_mat4 mat2 = new_mat4();
//	mat2.x_axis = vec4(2, 0,-1, 0);
//	mat2.y_axis = vec4(-1, 4, 3, 1);
//	mat2.z_axis = vec4(-5, 2, 0, 0);
//	mat2.w_axis = vec4(2, 0, 0, 1);
//	print_mat4(mat2);
//
//	print_mat4(mat4_mat4_multiply(mat1, mat2));
//
//	ft_putstr("\nNUCLEAR POLYGON BITCH\n");

	t_model		*model;
	t_fdf		fdf;
	double	x;
	double	y;

	check_argv(argv[1]);
	if (argc != 2)
		error(1);
	model = init_model();
	fdf.cam = camera(vec3(0.5, 0.5, 0.5)
					, vec3(0.0, 0.0, 0.0)
					, vec3(0.0, 1.0, 0.0));
	get_model(model, argv[1]);
	x = model->data[model->size_x / 2][model->size_x / 2]->pos.x;
	y = model->data[model->size_x / 2][model->size_x / 2]->pos.y;

	t_mat4 translate = create_translation(vec3(
			-(double)model->size_x/2 * STEP,
			-(double)model->size_y/2 * STEP,
			-5 * STEP
	));

	fdf.origin_model = copy_model(transform_model(translate, model));
	fdf.model = model;
	fdf.model = transform_model(fdf.cam, fdf.model);

	fdf.mlx = init_mlx();
	fdf.colr = VIOLET;
	draw_model(fdf);
	mlx_hook(fdf.mlx->win, 2, 5, hook_keydown, &fdf);
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
	if (key == Q || key == E)
	{
		(*fdf).model = z_rotate_key(key, fdf);
	}
	if (key == UP || key == DOWN || key == 65362 || key == 65364)
	{
		(*fdf).model = y_rotate_key(key, fdf);
	}
	if (key == MINUS || key == PLUS)
	{
		(*fdf).model = scale(fdf, key);
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
