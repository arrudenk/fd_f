/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                               :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:01:42 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/29 17:19:53 by arrudenk         ###   ########.fr       */
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
# include "keys.h"

# define VIOLET 0xA800DB
# define M_X(a, b) (fdf.model->data[a][b]->pos.x)
# define M_Y(a, b) (fdf.model->data[a][b]->pos.y)
# define POS(a, b) (model->data[a][b]->pos)
# define FDIMG (fdf.mlx->img->image)
# define W 1280
# define H 720
# define STEP 7
# define END -666.666

static int ran = 0;

typedef struct	s_image
{
	void	*image;
	char	*ptr;
	int		bpp;
	int		stride;
	int		endian;
}				t_image;

typedef	struct	s_draw
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	int		colr;
}				t_draw;

typedef	struct	s_mlx
{
	void	*mlx;
	void	*win;
	t_image	*img;
}				t_mlx;

typedef	struct	s_model
{
	t_point	***data;
	size_t	size_x;
	size_t	size_y;
}				t_model;

typedef	struct	s_fdf
{
	t_model	*model;
	t_mlx	*mlx;
	t_mat4	cam;
	int		colr;
}				t_fdf;

void			draw_model(t_fdf fdf);
void			draw_origin(t_mlx *mlx, t_mat4 *view_matrix);
t_draw			double4(double x1, double y1, double x2, double y2);
void			update(t_mat4 *camera, t_model *model);
int				ft_atoi_hex(char *s);
int				hook_keydown(int key, t_fdf *fdf);
t_mlx			*init_mlx(void);
t_model			*init_model(void);
int				get_model(t_model *model, char *file);
t_model			*copy_model(t_model *src);
void			print_vec3(t_vec3 v);
void			print_vec4(t_vec4 v);
void			print_model(t_model *map);
t_model			*transform_model(t_mat4 matrix, t_model *map);
t_model			*x_rotate_key(int key, t_fdf *fdf);
t_model			*y_rotate_key(int key, t_fdf *fdf);
t_model			*z_rotate_key(int key, t_fdf *fdf);
void			z_height(t_fdf fdf, int key);
t_mat4			destroy_z();
t_model			*scale(t_fdf *fdf, int key);



void			image_set_pixel(t_mlx *mlx, int x, int y, int c);
t_image			*new_image(t_mlx *mlx);
void			clear_image(t_mlx *mlx);

void			ft_free_2d(char **array);
void			ft_free_3d(char ***array);
t_mat4			rotation_around_centr(t_fdf fdf, int mod);
t_mat4			move_down(t_fdf fdf, int mod);
void			error(int error);

int				check_argv(char *argv);
void			check_point(char *data);

#endif
