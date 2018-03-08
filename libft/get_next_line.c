/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 14:54:56 by arrudenk          #+#    #+#             */
/*   Updated: 2018/02/23 14:54:58 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			discard_tail(t_tail *tail)
{
	char	*result;

	if (!tail->str[0])
		return (0);
	result = tail->str;
	if (!ft_strchr(tail->str, '\n'))
	{
		if (tail->str != NULL)
			ft_strdel(&tail->str);
		return (1);
	}
	tail->str = ft_strdup(ft_strchr(tail->str, '\n') + 1);
	ft_strdel(&result);
	return (1);
}

t_tail		**init_list(void)
{
	t_tail	**list;

	list = (t_tail**)ft_memalloc(sizeof(t_tail*));
	*list = NULL;
	return (list);
}

t_tail		*find_fd(t_tail **start, int fd)
{
	t_tail *tail;

	tail = *start;
	if (tail != NULL)
		while (tail != NULL && tail->fd != fd)
			tail = tail->next;
	if (tail == NULL)
	{
		tail = (t_tail*)ft_memalloc(sizeof(t_tail));
		tail->fd = fd;
		if (!(tail->str = ft_strnew(0)))
			return (NULL);
		tail->next = *start;
		*start = tail;
	}
	return (tail);
}

int			reader(t_tail *tail)
{
	ssize_t	bs;
	char	*buff;

	buff = ft_strnew(sizeof(char) * BUFF_SIZE);
	while ((bs = read(tail->fd, (void *)buff, BUFF_SIZE)))
	{
		if (bs == -1)
			return (-1);
		tail->str = ft_strjoin(tail->str, buff);
		ft_bzero(buff, BUFF_SIZE + 1);
		if ((ft_strchr(tail->str, '\n')))
			break ;
	}
	ft_strdel(&buff);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_tail	**list = NULL;
	t_tail			*t;

	if (fd < 0 || !line)
		return (-1);
	if (list == NULL)
		list = init_list();
	t = find_fd(list, fd);
	if (t == NULL)
		return (-1);
	if (t->str == NULL)
		return (0);
	if (reader(t) == -1)
		return (-1);
	if (!ft_strchr(t->str, '\n'))
		*line = ft_strsub(t->str, 0, ft_strlen(t->str));
	else
		*line = ft_strsub(t->str, 0, (ft_strchr(t->str, '\n') - t->str));
	return (discard_tail(t));
}
