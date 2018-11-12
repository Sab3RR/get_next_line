
#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
#include <sys/fcntl.h>

int     main(void)
{
    char *str;
    int *i;
    int fd;


printf("%lu\n", sizeof(t_list **));
    str = (char *)malloc(sizeof(char) * BUFF_SIZE);
    fd = open("/Users/vsusol/CLionProjects/get_next_line1/text", O_RDONLY);
    while (get_next_line(fd, &str) == 1)
        printf("%s", str);
    return 0;
}
