#include "so_long.h"

void	leakcheck(void)
{
	system("leaks --list a.out");
}

int main(void)
{
	atexit(leakcheck);
	int *aray;

	aray = malloc(sizeof(int) * 3);
	aray[0] = 2;
	printf("%d", aray[0]);
	free(aray);
	return(0);
}