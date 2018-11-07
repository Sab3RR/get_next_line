
#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
#include <sys/fcntl.h>

int     main(void)
{
    char *str;
    t_list *i;
    int fd;



    str = (char *)malloc(sizeof(char) * BUFF_SIZE);
    fd = open("C:\\Users\\vadim\\ClionProjects\\get_next_line\\text", O_RDONLY);
    i = get_next_line(fd, &str);
    close(fd);
    fd = open("C:\\Users\\vadim\\ClionProjects\\get_next_line\\text", O_RDONLY);
    i = get_next_line(fd, &str);
    free(str);
    str = ft_strnew(1);
    while (i)
    {
        str = ft_strjoin(str, (char *)i->content);
        i = i->next;
    }
    printf("%s", str);
    return 0;
}
