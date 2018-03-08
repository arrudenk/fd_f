/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:43:29 by arrudenk          #+#    #+#             */
/*   Updated: 2017/12/18 14:43:30 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_atoi(const char *str)
{
	int		i;
	int		nbr;
	int		negative;

	nbr = 0;
	negative = 1;
	i = 0;
	while ((*(str + i) == '\n') ||
			(*(str + i) == '\t') ||
			(*(str + i) == '\v') ||
			(*(str + i) == ' ') ||
			(*(str + i) == '\f') ||
			(*(str + i) == '\r'))
		i++;
	if (*(str + i) == '-')
		negative = -1;
	if (*(str + i) == '+' || *(str + i) == '-')
		i++;
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
		nbr = nbr * 10 + (*(str + i++) - '0');
	return (nbr * negative);
}
