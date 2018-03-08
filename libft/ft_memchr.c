/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:29:37 by arrudenk          #+#    #+#             */
/*   Updated: 2017/12/18 13:29:38 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *in, int fnd, size_t cnt)
{
	const char	*inc;
	size_t		i;

	inc = (const char *)in;
	i = -1;
	while (++i < cnt)
		if (*(inc + i) == (char)fnd)
			return ((void *)inc + i);
	return (NULL);
}
