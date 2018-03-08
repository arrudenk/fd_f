/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:15:51 by arrudenk          #+#    #+#             */
/*   Updated: 2017/12/14 13:16:10 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	rage;
	char	*set;

	rage = 0;
	set = s;
	while (rage < n)
		*(set + rage++) = c;
	return (s);
}
