#include <stdio.h>
#include <stdlib.h>

int bin2dec(int ac, char **av)
{

	int a = 0;
	int i = 0;

	while(av[1][i])
	{
		a |= (av[1][i] - 48);
		i++;
		if (av[1][i])
			a <<= 1;
	}
	return(a);
}

int main(int ac, char **av)
{
	printf("%d\n", bin2dec(ac, av));
	return(0);
}
