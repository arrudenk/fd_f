//
// Created by Artem RUDENKO on 3/30/18.
//

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

//void		ft_free_model(t_model *model)
//{
//
//}