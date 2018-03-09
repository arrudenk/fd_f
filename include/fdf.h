/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:01:42 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/07 13:01:43 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
//# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include "libft.h"

#define VIOLET 0xA800DB

#define WIDTH 640
#define HEIGHT 480

typedef struct	s_pixel
{
	double	x;
	double	y;
	int		z;
}				t_pixel;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct	s_map
{
	char		**map;
	t_pixel		**pixels;
}				t_map;

void			draw_line(t_mlx *map,double x1, double y1, double x2, double y2, int color);
int				hook_keydown(int key);
t_pixel			*new_pixel(char *map);
t_mlx			*init_mlx(void);

#endif
