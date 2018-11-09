
#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
#include <sys/fcntl.h>

int     main(void)
{
    char *str;
    t_list *i;
    int fd;


printf("%lu\n", sizeof(t_list **));
    str = (char *)malloc(sizeof(char) * BUFF_SIZE);
    fd = open("/Users/vsusol/CLionProjects/get_next_line1/text", O_RDONLY);
    i = get_next_line(fd, &str);
    str = ft_strnew(1);
    while (i)
    {
        str = ft_strnjoin(str, (char *)i->content, i->content_size);
        i = i->next;
    }
    printf("%s", str);
    fd = open("/Users/vsusol/CLionProjects/get_next_line1/text", O_RDONLY);
    i = get_next_line(fd, &str);
    free(str);
    str = ft_strnew(1);
    while (i)
    {
        str = ft_strnjoin(str, (char *)i->content, i->content_size);
        i = i->next;
    }
    printf("%s", str);
    return 0;
}
