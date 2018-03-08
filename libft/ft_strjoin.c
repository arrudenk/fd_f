/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:31:29 by arrudenk          #+#    #+#             */
/*   Updated: 2017/12/20 14:31:30 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	nstr = ft_strnew(s1_len + s2_len);
	if (!nstr)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < s1_len)
		*(nstr + i) = *(s1 + i);
	while (++j < s2_len)
		*(nstr + i++) = *(s2 + j);
	free((char *)s1);
	return (nstr);
}
