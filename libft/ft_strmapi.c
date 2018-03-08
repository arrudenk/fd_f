/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 13:47:41 by arrudenk          #+#    #+#             */
/*   Updated: 2017/12/20 13:47:43 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			n;
	size_t			len;
	char			*s_new;

	n = 0;
	i = 0;
	s_new = NULL;
	if (s != NULL)
	{
		len = ft_strlen(s);
		s_new = (char*)malloc(sizeof(char) * len + 1);
		if (s_new != NULL)
		{
			while (n < len)
			{
				s_new[n] = f(i, s[n]);
				n++;
				i++;
			}
			s_new[n] = '\0';
		}
	}
	return (s_new);
}
