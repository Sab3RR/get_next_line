
#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

int     main(void)
{
    char *str;
    int i;

    str = (char *)malloc(sizeof(char) * BUFF_SIZE);
    i = get_next_line(1, &str);
    printf("%d", i);
    return 0;
}
