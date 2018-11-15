/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsusol <vsusol@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:10:15 by vsusol            #+#    #+#             */
/*   Updated: 2018/11/06 13:10:19 by vsusol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	**malloc_list(t_list ***list, t_list **fd_list, int fd)
{
	t_list	*fd_lst;
	t_list	**lst;
	long	i;

	if (!*list)
		if (!(list[0] = (t_list **)malloc(sizeof(t_list*))) || (list[0][0] = NULL))
			return (NULL);
	if (!*fd_list)
	{
		if (!(*fd_list = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		(*fd_list)->content = (void *)0;
		(*fd_list)->content_size = (size_t)fd;
		(*fd_list)->next = NULL;
	}
	i = 0;
	fd_lst = *fd_list;
	while (fd_lst)
	{
		if ((int)fd_lst->content_size == fd)
		{
			return ((*list) + (long)fd_lst->content);
		}
		i++;
		fd_lst = fd_lst->next;
	}
	if (!(lst = malloc((i + 1) * sizeof(t_list*))))
		return (NULL);
	ft_memcpy(lst, *list, i * sizeof(t_list**));
	free(*list);
	*list = lst;
	lst[i] = NULL;
	if (!(fd_lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	fd_lst->content = (void *)i;
	fd_lst->content_size = (size_t)fd;
	fd_lst->next = NULL;
	ft_lstpushback(*fd_list, fd_lst);
	return (lst + i);
}

int				create_list(int fd, t_list **list)
{
	int				end;
	int				start;
	t_list			*new;
	char			*str;

	if (!(str = ft_strnew(sizeof(char) * (BUFF_SIZE + 1))))
		return (0);
	if (((int)read(fd, str, BUFF_SIZE)))
	{
		end = 0;
		while (str[end])
		{
			start = end;
			end = ft_findichar(str + start, '\n') + start + 1;
			if (!(new = ft_lstnew((str + start), (size_t)(end - start))))
				return (0);
			if (!list[0])
				list[0] = new;
			else
				ft_lstpushback(list[0], new);

		}
		free(str);

	}
	else
	{
		free(str);
		return (0);
	}
	return (1);
}

int     cheack_fd(int fd, char **line)
{
	if (!line)
		return (0);
	if (fd > 4863)
		return (0);
	if (read(fd, "", 0) == -1)
		return (0);
	return (1);
}

int     get_next_line(const int fd, char **line)
{
	static t_list	***list;
	t_list			**array;



	if (!cheack_fd(fd, line))
		return (-1);
	if (!list)
	{
		if (!(list = (t_list ***)malloc(sizeof(t_list **) * 2)))
			return (0);
		list[0] = NULL;
		if (!(list[1] = (t_list **)malloc(sizeof(t_list *))))
			return (0);
		list[1][0] = NULL;
	}
	if (!(array = malloc_list(list, list[1], fd)))
		return (0);
	if (!*array)
		create_list(fd, array);
	*line = (char *)malloc(sizeof(char));
	**line = '\0';
	while (*array)
	{
		*line = ft_strnjoin(*line, (char *)(*array)->content, (*array)->content_size);
		if (*(*line + ft_strlen(*line) - 1) == '\n' && !(*(*line + ft_strlen(*line) - 1) = '\0'))
		{
			*array = ft_lstfree(*array);
			return (1);
		}
		*array = ft_lstfree(*array);
		if (create_list(fd, array))
		{
			*line = ft_strnjoin(*line, (char *)(*array)->content, (*array)->content_size);
			if (*(*line + ft_strlen(*line) - 1) == '\n' && !(*(*line + ft_strlen(*line) - 1) = '\0'))
			{
				*array = ft_lstfree(*array);
				return (1);
			}
			*array = ft_lstfree(*array);
			create_list(fd, array);
		}


	}
	if (**line)
		return (1);




	return (0);
}

