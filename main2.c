#include "libfts.h"
#include <stdio.h>

int main(void)
{
	int c = 100;

	printf("c= %i  |  c = %i\n", ft_tolower(c), ft_toupper(c));
}