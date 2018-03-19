/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                              :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:01:25 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/14 15:10:10 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			main(int argc, char **argv)
{
	t_vec3	*pix;
	t_mlx	*mlx;
	t_model	*model;
	t_vec4	***mapa;
	char	*file = "../maps/pyramid";

	mlx = init_mlx();
	model = init_model();
	get_map(model, file);
	// ############ MAP INITIALIZATION #############

	t_vec3 eye	= vec3(0.5, 0.5, -0.5);
	t_vec3 tar	= vec3(0.0, 0.0, 1.0);
	t_vec3 up	= vec3(0.0, 1.0, 0.0);

	t_mat4 *test_view = look_at(eye, tar, up);
	t_model *trans_model = transform_model(test_view, model);

	draw_model(mlx, trans_model);
	draw_origin(mlx, test_view);
	mlx_key_hook(mlx->win, hook_keydown, NULL);
	mlx_loop(mlx->mlx);
	return (0);
}

int			hook_keydown(int key)
{
	if (key == 65307 || key == 53)
		exit(1);
	return (0);
}


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

void		print_model(t_model *model)
{
	for (int i=0; i < model->size_x; i++)
	{
		for (int j=0; j < model->size_y; j++)
		{
			print_vec4(model->data[i][j]->pos);
		}
	}
}

t_model		*copy_model(t_model *src)
{
	t_model *new_model;
	new_model = init_model();

	int i;
	int j;

	i = -1;
	new_model->data = ft_memalloc(sizeof(t_point *) * src->size_x);
	while (++i < src->size_x)
	{
		j = -1;
		new_model->data[i] = ft_memalloc(sizeof(t_point *) * src->size_y);
		while (++j < src->size_y)
		{
			new_model->data[i][j] = ft_memalloc(sizeof(t_point));
			ft_memcpy((void*) new_model->data[i][j], (void*) src->data[i][j], sizeof(t_point));
		}
	}

	return (new_model);
}

t_model		*transform_model(t_mat4 *matrix, t_model *model)
{
	t_model *new_model = copy_model(model);

	new_model->data = ft_memalloc(sizeof(t_point *) * model->size_x);
	for (int i=0; i < model->size_x; i++)
	{
		new_model->data[i] = ft_memalloc(sizeof(t_point *) * model->size_y);
		for (int j=0; j < model->size_y; j++)
		{
			new_model->data[i][j] = ft_memalloc(sizeof(t_point));
			new_model->data[i][j]->pos = vec4_mat4_multiply(model->data[i][j]->pos, matrix);
		}
	}

	new_model->size_x = model->size_x;
	new_model->size_y = model->size_y;

	return (new_model);
}