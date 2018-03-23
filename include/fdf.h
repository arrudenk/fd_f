/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                               :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:01:42 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/22 15:10:40 by arrudenk         ###   ########.fr       */
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

# define WIDTH 1280
# define HEIGHT 720
# define STEP 10


typedef	struct	s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef	struct	s_model
{
	t_point	***data;
	size_t	size_x;
	size_t	size_y;
}				t_model;

typedef	struct	s_fdf
{
	t_model		*model;
	t_mlx		*mlx;
	t_mat4		*cam;
}				t_fdf;

void			draw_line(t_mlx *mlx, double x1, double y1, double x2, double y2, int color);
void			draw_line_h(t_mlx *mlx, double x1, double y1, double x2, double y2, int color);
void			draw_line_v(t_mlx *mlx, double x1, double y1, double x2, double y2, int color);
void			draw_model(t_mlx *mlx, t_model *model);
void			draw_origin(t_mlx *mlx, t_mat4 *view_matrix);

void			update(t_mat4 *camera, t_model *model);

int				ft_atoi_hex(char *s);

int			hook_keydown(int key, t_fdf *fdf);

t_mlx			*init_mlx(void);
t_model			*init_model(void);
int				get_map(t_model *model, char *file);
t_model			*copy_model(t_model *src);


void			print_vec3(t_vec3 *v);
void			print_vec4(t_vec4 *v);
void			print_model(t_model *map);

t_model			*transform_model(t_mat4 *matrix, t_model *map);

void		x_rotate_key(int key, t_fdf *fdf);
void		y_rotate_key(int key, t_fdf *fdf);
void		rotate_Z(t_mlx *mlx, t_model *model);
void		back_rotate_Z(t_mlx *mlx, t_model *model);


#endif
