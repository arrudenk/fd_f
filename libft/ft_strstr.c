/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:47:18 by arrudenk          #+#    #+#             */
/*   Updated: 2017/12/13 13:47:19 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *dest, const char *source)
{
	size_t gear;
	size_t cnt;

	if (*source == '\0')
		return ((char*)dest);
	gear = 0;
	while (dest[gear])
	{
		cnt = 0;
		while (dest[gear + cnt] == source[cnt])
		{
			cnt++;
			if (source[cnt] == '\0')
				return ((char *)dest + gear);
		}
		gear++;
	}
	return (0);
}
