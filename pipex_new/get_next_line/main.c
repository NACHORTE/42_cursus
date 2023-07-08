#include "get_next_line.h"
# include <fcntl.h>
#include <stdio.h>


int main(void)
{
    int fd;
    char *str;
	str = "hola";
    fd = open("texto.txt", O_RDONLY);

	while (1)
	{
		str = get_next_line(fd);
		if (str == 0)
			return (0);
    	printf("%s", str);
	}
    return 0;
}