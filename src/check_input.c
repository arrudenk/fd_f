/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:13:38 by arrudenk          #+#    #+#             */
/*   Updated: 2018/04/03 15:13:39 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			ft_ishex(size_t c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 70) || (c >= 97 && c <= 102))
		return (1);
	else
		return (0);
}

int			check_argv(char *argv)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (get_next_line(fd, &line) <= 0 || fd <= 0)
	{
		ft_strdel(&line);
		error(-1);
	}
	ft_strdel(&line);
	return (0);
}

static void	check_color(char *data)
{
	int	i;

	if (data[0] != '0' || data[1] != 'x')
		error(7);
	if (ft_strlen(data + 2) != 6)
		error(7);
	i = 1;
	while (data[++i])
	{
		if (!ft_ishex((size_t)data[i]))
			error(7);
	}
}

void		check_point(char *data)
{
	int i;

	i = data[0] == '-' ? 0 : -1;
	while (data[++i])
	{
		if (data[i] == ',' && i > 0)
		{
			check_color(data + ++i);
			break ;
		}
		if (!ft_isdigit(data[i]))
			error(7);
	}
}
