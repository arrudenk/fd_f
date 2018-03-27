/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create image.c                                      :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:04:49 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/27 18:06:27 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
//TODO: add this to draw!!!
void	image_set_pixel(t_fdf *fdf, int x, int y, int c)
{
	*(int *)(fdf->img->ptr + ((x + y * W) * fdf->img->bpp)) = c;
}

void	clear_image(t_fdf *fdf)
{
	int		i;

	i = W * H * fdf->img->bpp;
	while (--i)
		*(fdf->img->ptr + i) = 0;
	*(fdf->img->ptr) = 0;
}

t_image	*new_image(t_fdf *fdf)
{
	t_image	*img;

	if (!(img = (t_image *)malloc(sizeof(t_image))))
	{
		ft_putendl("error");
		exit(1);
	}
	if (!(img->image = mlx_new_image(fdf->mlx, W, H)))
	{
		ft_putendl("error");
		exit(1);
	}
	img->ptr = mlx_get_data_addr(img->image, &(img->bpp), &(img->stride)
			, &(img->endian));
	img->bpp = (img->bpp) >> 3;
	return (img);
}
