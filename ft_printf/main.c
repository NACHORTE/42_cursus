#include "ft_printf.h"
#include <stdio.h>
int	main(int c, char **v)
{
	int a;
	a = 1;
	printf("\n%d\n", ft_printf("%p", (void *)-14523));
	printf("\n");
	printf("\n");
	return (0);
}