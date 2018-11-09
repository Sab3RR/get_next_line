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

static t_list    **malloc_list(t_list ***list, t_list **fd_list, int fd)
{
    t_list  *fd_lst;
    t_list  **lst;
    int     i;

    if (!*list)
        if (!(list[0] = (t_list **)malloc(sizeof(t_list*))) || (list[0][0] = NULL))
            return (NULL);
    if (!*fd_list)
    {
        if (!(*fd_list = (t_list *)malloc(sizeof(t_list))))
            return (NULL);
        (*fd_list)->content = list[0];
        (*fd_list)->content_size = (size_t)fd;
        (*fd_list)->next = NULL;
    }
    i = 0;
    fd_lst = *fd_list;
    while (fd_lst)
    {
        if ((int)fd_lst->content_size == fd)
            return ((t_list **)fd_lst->content);
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
    fd_lst->content = lst + i;
    fd_lst->content_size = fd;
    fd_lst->next = NULL;
    ft_lstpushback(*fd_list, fd_lst);
    return (lst + i);
}

int     create_list(int fd, t_list **list)
{
    int             byte;
    int             n;
    int             end;
    int             start;
    t_list          *new;
    char            *str;

    if (!(str = ft_strnew(BUFF_SIZE)))
        return (0);
    n = 0;
    if ((byte = (int)read(fd, str, BUFF_SIZE - 1)))
    {
        printf("1\n");
        str[byte] = '\0';
        n += byte;
        end = 0;
        while (str[end])
        {
            start = end;
            end = ft_findichar(str + start, '\n') + start + 1;
            if (!(new = ft_lstnew((str + start), (size_t)(end - start))))
                return (0);
            printf("%i\n%s\n", n, (char *)new->content);
            if (!list[0])
                list[0] = new;
            else
                ft_lstpushback(list[0], new);

        }

    }
}

t_list     *get_next_line(const int fd, char **line)
{
	static t_list   **list;
	static t_list   *fd_list;
    t_list          **array;





    if (!(array = malloc_list(&list, &fd_list, fd)))
        return (0);
    create_list(fd, array);




    return (*array);
}

