
#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
#include <sys/fcntl.h>
#include <time.h>

int     main(void)
{
    char *str;
    int i;
    int fd;
    clock_t t;




printf("%lu\n", sizeof(t_list **));
    str = (char *)malloc(sizeof(char) * BUFF_SIZE);
    fd = open("/Users/vsusol/CLionProjects/get_next_line1/2600-0.txt", O_RDONLY);
    t = clock();
    i = 0;
    while(get_next_line(fd, &str) && ++i)
        printf("%s\n", str);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("%f\n", time_taken);
    printf("%i", i);

    return 0;
}
