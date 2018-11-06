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
    t_list          *new;
    size_t             n;
    size_t          byte;
    int             i;
    int             start;
    int             end;
	char            *str;
	char            **array;


	if (!list)
		if (!(list = (t_list **)malloc(sizeof(t_list))))
			return (0);
	if (!*list)
	    *list = NULL;
	if (!(str = ft_strnew(BUFF_SIZE)))
	    return (0);
	end = 0;
	start = 0;
	n = 0;
	while ((byte = (size_t)read(fd, str, BUFF_SIZE - 1)))
    {
        str[n] = '\0';
	    while (str[end])
        start = end;
        end = ft_findichar(str, '\n');
        if (!(new = ft_lstnew((str + start), end - start)))
            return (0);
        if (!*list)
            *list = new;
        else
            ft_lstpushback(*list, new);
        n += byte;
    }

    return ((int)n);
}

