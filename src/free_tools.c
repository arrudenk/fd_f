/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:55:10 by arrudenk          #+#    #+#             */
/*   Updated: 2018/04/04 12:55:12 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		ft_free_2d(char **array)
{
	int f;

	f = -1;
	while (array[++f])
	{
		ft_strdel(&array[f]);
	}
	free(array);
}

void		ft_free_3d(char ***array)
{
	int f;

	f = -1;
	while (array[++f])
	{
		ft_free_2d(array[f]);
	}
	free(array);
}

void		ft_free_model(t_model *model)
{
	int a;
	int b;

	a = -1;
	while (++a < model->size_x)
	{
		b = -1;
		while (++b < model->size_y)
		{
			ft_memdel((void *)&model->data[a][b]);
		}
	}
	a = -1;

	while (++a < model->size_x)
	{
		ft_memdel((void *)&model->data[a]);
	}
	ft_memdel((void *)&model->data);
	ft_memdel((void *)&model);
}