/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 13:09:17 by arrudenk          #+#    #+#             */
/*   Updated: 2017/12/20 13:09:21 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*a;
	size_t	n;

	a = NULL;
	i = 0;
	if (s != NULL)
	{
		n = ft_strlen(s);
		a = (char*)malloc(sizeof(char) * n + 1);
		if (a != NULL)
		{
			while (i < n)
			{
				*(a + i) = f(*(s + i));
				i++;
			}
			*(a + i) = '\0';
		}
	}
	return (a);
}
