/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                              :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:01:25 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/29 16:19:10 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_model	*model;
	char	*file = "../maps/pyramid";

	mlx = init_mlx();
	model = init_model();
	get_model(model, file);
	t_vec3 eye = vec3(0.5, 0.0, 0.0);
	t_vec3 tar = vec3(1.0, 0.0, 0.0);
	t_vec3 up = vec3(0.0, 1.0, 0.0);

	t_mat4 *rotation_mat = create_x_rotation(60);

	t_mat4 *test_view = look_at(&eye, &tar, &up);
	t_model *trans_model = transform_model(rotation_mat, model);
	trans_model = transform_model(test_view, trans_model);


	t_fdf fdf;
	fdf.model = trans_model;
	fdf.mlx = mlx;
	fdf.cam = test_view;
	draw_model(mlx, trans_model);
	draw_origin(mlx, test_view);
	//mlx_clear_window(mlx->mlx, mlx->win);

	mlx_hook(mlx->win,2,5, hook_keydown, &fdf);
	mlx_loop(mlx->mlx);
	return (0);
}

int			hook_keydown(int key, t_fdf *fdf)
{
	if (key == 65307 || key == 53)
	{
		exit(1);
	}
	if (key == LEFT || key == RIGHT || key == 65363 || key == 65361)// <-...->
	{
		x_rotate_key(key, fdf);
	}
	if (key == UP || key == DOWN)// ^...v
	{
		y_rotate_key(key, fdf);
	}
	if (key == MINUS || key == PLUS)
	{
		z_rotate_key(key, fdf);
	}
	return (0);
}

//TODO: del this or use
void		print_vec3(t_vec3 *v)
{
	ft_putstr("vec3: ");
	ft_putnbr(v->x);
	ft_putstr(", ");
	ft_putnbr(v->y);
	ft_putstr(", ");
	ft_putnbr(v->z);
	ft_putchar('\n');
}

void		print_vec4(t_vec4 *v)
{
	ft_putstr("vec4: ");
	ft_putnbr(v->x);
	ft_putstr(", ");
	ft_putnbr(v->y);
	ft_putstr(", ");
	ft_putnbr(v->z);
	ft_putstr(", ");
	ft_putnbr(v->w);
	ft_putchar('\n');
}
