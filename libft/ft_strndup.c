/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:15:19 by arrudenk          #+#    #+#             */
/*   Updated: 2017/12/21 13:52:44 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strndup(const char *str1, size_t len)
{
	char	*tmp;

	if (!(tmp = ft_strnew(len)))
		return (NULL);
	ft_strncpy(tmp, str1, len);
	return (tmp);
}
