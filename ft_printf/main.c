#include "ft_printf.h"
#include <stdio.h>
int	main(int c, char **v)
{
	int a;
	a = 0;
	printf("\n%d\n", ft_printf(v[1], NULL));
	return (0);
}