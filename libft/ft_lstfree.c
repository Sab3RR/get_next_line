#include "libft.h"

t_list  *ft_lstfree(t_list *alst)
{
    t_list  *buff;

    buff = alst->next;
    free(alst->content);
    free(alst);
    return (buff);
}
