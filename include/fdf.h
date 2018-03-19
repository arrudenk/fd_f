/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                               :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:01:42 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/14 15:09:06 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include "libft.h"
# include "vector_math.h"

# define VIOLET 0xA800DB

# define WIDTH 640
# define HEIGHT 480
# define STEP 10

typedef	struct	s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef	struct	s_model
{
	t_vec4	***data;
	size_t	size_x;
	size_t	size_y;
}				t_model;

void			draw_line(t_mlx *map, double x1, double y1, double x2, double y2, int color);
void			draw_line_h(t_mlx *map, double x1, double y1, double x2, double y2, int color);
void			draw_line_v(t_mlx *map, double x1, double y1, double x2, double y2, int color);
void			draw_model(t_mlx *mlx, t_model *map);
void			draw_origin(t_mlx *mlx, t_mat4 *view_matrix);

int				ft_atoi_hex(char *s);

int				hook_keydown(int key);

t_mlx			*init_mlx(void);
t_model			*init_map(void);
int				get_map(t_model *model, char *file);


void			print_vec3(t_vec3 *v);
void			print_vec4(t_vec4 *v);
void			print_map(t_model *map);

t_model			*transform_map(t_mat4 *matrix, t_model *map);



#endif
