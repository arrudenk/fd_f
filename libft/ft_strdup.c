/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:03:09 by arrudenk          #+#    #+#             */
/*   Updated: 2017/11/21 15:03:10 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *str1)
{
	size_t	n;
	size_t	m;
	char	*ret;

	n = 0;
	m = 0;
	while (str1[n] != '\0')
		n++;
	if (!(ret = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	else
	{
		while (m < n)
		{
			ret[m] = str1[m];
			m++;
		}
		ret[m] = '\0';
		return (ret);
	}
}
