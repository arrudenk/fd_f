/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:57:48 by arrudenk          #+#    #+#             */
/*   Updated: 2017/12/13 10:57:49 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncat(char *dest, const char *str, size_t n)
{
	int		i;
	int		j;

	i = -1;
	j = (int)ft_strlen(dest);
	while (*(str + ++i) && i < (int)n)
		*(dest + j++) = *(str + i);
	*(dest + j) = '\0';
	return (dest);
}
