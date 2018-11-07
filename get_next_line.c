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
    int             n;
    int             byte;
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
    n = 0;



    while ((byte = (int)read(fd, str, BUFF_SIZE - 1)))
    {
	    printf("1\n");
        str[byte] = '\0';
        n += byte;
        end = 0;
        start = 0;
	    while (str[end])
        {
            start = end + 1;
            end = ft_findichar(str + start, '\n') + start;
            if (!(new = ft_lstnew((str + start), (size_t)(end - start))))
                return (0);
            printf("%i\n%s\n", n, (char *)new->content);
            if (!*list)
                *list = new;
            else
                ft_lstpushback(*list, new);

        }

    }

    return (n);
}

