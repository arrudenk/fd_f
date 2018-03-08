/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:19:48 by arrudenk          #+#    #+#             */
/*   Updated: 2017/12/20 14:19:49 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*ret;
	size_t		n;

	if (s)
	{
		if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		if (len == 0)
		{
			ret[0] = '\0';
			return (ret);
		}
		n = 0;
		while (n < len && s[start] != '\0')
			ret[n++] = s[start++];
		ret[n] = '\0';
		while (n < len)
		{
			ret[n] = '\0';
			n++;
		}
		return (ret);
	}
	return (NULL);
}
