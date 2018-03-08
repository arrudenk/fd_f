/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:19:11 by arrudenk          #+#    #+#             */
/*   Updated: 2017/12/19 15:19:13 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdel(t_list **adlst, void (*del)(void *, size_t))
{
	if ((*adlst)->next)
		ft_lstdel(&(*adlst)->next, del);
	ft_lstdelone(&(*adlst), del);
}
