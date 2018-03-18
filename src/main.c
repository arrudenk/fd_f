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
	t_model	*map;
	t_vec4	***mapa;
	char	*file = "../maps/test2";

	mlx = init_mlx();
	map = init_map();
	get_map(map, file);
	// ############ MAP INITIALIZATION #############

	t_vec3 eye	= vec3(0.5, 0.5, -0.5);
	t_vec3 tar	= vec3(0.0, 0.0, 1.0);
	t_vec3 up	= vec3(0.0, 1.0, 0.0);

	t_mat4 *test_view = look_at(eye, tar, up);
	t_model *trans_map = transform_map(test_view, map);
	print_map(trans_map);

	draw_map(mlx, trans_map);
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

void		print_map(t_model *map)
{
	for (int i=0; i < map->size_x; i++)
	{
		for (int j=0; j < map->size_y; j++)
		{
			print_vec4(map->data[i][j]);
		}
	}
}

t_model		*transform_map(t_mat4 *matrix, t_model *map)
{
	t_model *transformed_map;
	transformed_map = init_map();

	transformed_map->data = ft_memalloc(sizeof(t_vec4 *) * map->size_x);
	for (int i=0; i < map->size_x; i++)
	{
		transformed_map->data[i] = ft_memalloc(sizeof(t_vec4 *) * map->size_y);
		for (int j=0; j < map->size_y; j++)
		{
			transformed_map->data[i][j] = vec4_mat4_multiply(map->data[i][j], matrix);
		}
	}

	transformed_map->size_x = map->size_x;
	transformed_map->size_y = map->size_y;

	return (transformed_map);
}