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

int     get_next_line(const int fd, char **line)
{
	static t_list   **list;
	static t_list   *fd_list;
	int             n;
	char            *str;
	t_list          *new;

	if (!list)
		if (!(list = (t_list **)malloc(sizeof(t_list))))
			return (0);
	if (!*list)
	    *list = NULL;
	if (!(str = ft_strnew(BUFF_SIZE)))
	    return (0);
	n = read(fd, str, BUFF_SIZE - 1);
	str[n] = '\0';
    if (!(new = ft_lstnew(str, BUFF_SIZE)))
        return (0);
    ft_lstadd(list, new);
    return (n);
}

