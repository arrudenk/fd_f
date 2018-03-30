/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 00:36:30 by arrudenk          #+#    #+#             */
/*   Updated: 2018/03/30 00:36:31 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		ft_valid_color(char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != ' ')
	{
		if ((s[i] >= 'A' && s[i] <= 'F') || (s[i] >= '0' && s[i] <= '9'))
			i++;
		else if ((s[i] >= 'a' && s[i] <= 'f'))
			i++;
		else
		{
			ft_putstr("ERROR: COLLOR");
			exit(1);
		}
	}
}

int				ft_atoi_hex(char *s)
{
	int		i;
	int		res;

	ft_valid_color(s);
	res = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'f')
			s[i] = s[i] - 32;
		i++;
	}
	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			res = res * 16 + (s[i] - 48);
		else if (s[i] >= 'A' && s[i] <= 'F')
			res = res * 16 + (s[i] - 55);
		i++;
	}
	return (res);
}
