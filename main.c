
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
    int fd1;
    clock_t t;
    FILE * f;




printf("%lu\n", sizeof(t_list **));
    str = (char *)malloc(sizeof(char) * BUFF_SIZE);
    fd = open("C:\\Users\\vadim\\CLionProjects\\get_next_line\\2600-0.txt", O_RDONLY);
    fd1 = open("C:\\Users\\vadim\\CLionProjects\\get_next_line\\test.txt", O_CREAT, O_RDWR);
    char strr[BUFF_SIZE];
    t = clock();
    i = 0;
    while(get_next_line(fd, &str) && ++i)
    {
        write(1, str, ft_strlen(str));
        write(1, "\n", 1);

    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("%f\n", time_taken);
    printf("%i", i);
    close(fd);
    close(fd1);
    return 0;
}
