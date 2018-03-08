/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:19:32 by arrudenk          #+#    #+#             */
/*   Updated: 2017/12/19 15:19:33 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdelone(t_list **adlst, void (*del)(void *, size_t))
{
	del((*adlst)->content, (*adlst)->content_size);
	free(*adlst);
	*adlst = NULL;
}
