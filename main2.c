#include "libfts.h"
#include <stdio.h>

int main(void)
{
	char	*dest = malloc(sizeof(char) * 100);
	char	*src = malloc(sizeof(char) * 100);
	bzero(dest, 100);
	bzero(src, 100);
	sprintf(src, "qwert\tyuiop\n");
	sprintf(dest, "qwert\tyuiop\n");
	ft_write(1, src, 20);
	write(1, "\n", 1);
	write(1, dest, 20);

	bzero(dest, 100);
	bzero(src, 100);
	read(0, dest, 10);
	printf("%s\n", dest);
	ft_read(0, src, 10);
	printf("%s\n", src);
}
