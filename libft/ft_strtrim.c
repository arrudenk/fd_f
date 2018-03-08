/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:48:07 by arrudenk          #+#    #+#             */
/*   Updated: 2017/12/20 14:48:09 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s)
{
	char			*s_new;
	unsigned int	i;
	int				n;
	unsigned int	l;

	if (s == NULL)
		return (NULL);
	i = 0;
	n = 0;
	l = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while ((s[l] == ' ' || s[l] == '\n' || s[l] == '\t'
			|| s[l] == '\0') && l != 0)
		l--;
	s_new = (char*)malloc(sizeof(char) * (l - i + 2));
	if (s_new == NULL)
		return (NULL);
	while (i <= (unsigned int)l && l != '\0')
		s_new[n++] = s[i++];
	s_new[n] = '\0';
	return (s_new);
}
