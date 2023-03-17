#include "ft_printf.h"
#include <stdio.h>
int	main(int c, char **v)
{
	printf("%d", ft_printf(v[1], NULL));
	return (0);
}