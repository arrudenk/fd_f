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
# include "vector_math.h"

#define VIOLET 0xA800DB

#define WIDTH 640
#define HEIGHT 480
#define STEP 25

typedef	struct	s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef	struct	s_map
{
	t_vec4	***data;
	int		size_x;
	int		size_y;
}				t_map;

void			draw_line(t_mlx *map, double x1, double y1, double x2, double y2, int color);
void			draw_line_h(t_mlx *map, double x1, double y1, double x2, double y2, int color);
void			draw_line_v(t_mlx *map, double x1, double y1, double x2, double y2, int color);
void			draw_map(t_mlx *mlx, t_map *map);

int				hook_keydown(int key);

t_mlx			*init_mlx(void);
t_map			*init_map();

void			print_vec3(t_vec3 *v);
void			print_vec4(t_vec4 *v);
void			print_map(t_map *map);

t_map			*transform_map(t_mat4 *matrix, t_map *map);



#endif
