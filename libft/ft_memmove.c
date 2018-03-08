/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 09:39:45 by arrudenk          #+#    #+#             */
/*   Updated: 2017/12/18 09:39:47 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*to;
	char	*from;

	to = (char *)dest;
	from = (char *)src;
	if (from < to)
		while (n--)
			to[n] = from[n];
	else
		ft_memcpy(to, from, n);
	return (to);
}
