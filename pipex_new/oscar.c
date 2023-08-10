#include <stdio.h>
#include <errno.h>

int main(void)
{
	for (int i = 0; i<200; i++)
	{
		errno = i;
		perror(NULL);
	}
	return(0);
}