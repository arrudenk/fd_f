
#include "../include/fdf.h"

void		print_vec3(t_vec3 v)
{
	ft_putstr("vec3: ");
	ft_putnbr(v.x);
	ft_putstr(", ");
	ft_putnbr(v.y);
	ft_putstr(", ");
	ft_putnbr(v.z);
	ft_putchar('\n');
}

void		print_vec4(t_vec4 v)
{
	ft_putstr("vec4: ");
	ft_putnbr(v.x);
	ft_putstr(", ");
	ft_putnbr(v.y);
	ft_putstr(", ");
	ft_putnbr(v.z);
	ft_putstr(", ");
	ft_putnbr(v.w);
	ft_putchar('\n');
}

void		print_mat4(t_mat4 mat)
{
	ft_putstr("mat4: {\n");
	print_vec4(mat.x_axis);
	print_vec4(mat.y_axis);
	print_vec4(mat.z_axis);
	print_vec4(mat.w_axis);
	ft_putstr("}\n");

}