/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:41:06 by arrudenk          #+#    #+#             */
/*   Updated: 2017/12/13 12:41:08 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *string, int symbol)
{
	int	a;

	a = -1;
	while (++a < (int)ft_strlen(string) + 1)
		if (*(string + a) == (char)symbol)
			return ((char *)string + a);
	return (NULL);
}
