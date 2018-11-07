
#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
#include <sys/fcntl.h>

int     main(void)
{
    char *str;
    int i;
    int fd;



    str = (char *)malloc(sizeof(char) * BUFF_SIZE);
    fd = open("E:\\get_next_line-getnextline\\text", O_RDONLY);
    i = get_next_line(fd, &str);
    printf("%d", i);
    return 0;
}
