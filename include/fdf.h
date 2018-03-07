#ifndef FD_F_FDF_H
# define FD_F_FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

#define VIOLET 0xA800DB

#define WIDTH 640
#define HEIGHT 480

typedef struct s_pixel {
	int x;
	int y;
	int color;
} t_pixel;

void 	draw_line(void* mlx_ptr, void* win_ptr, double x1, double y1, double x2, double y2, int color);
int		hook_keydown(int key);


#endif //FD_F_FDF_H
