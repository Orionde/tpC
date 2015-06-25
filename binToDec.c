#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binToDec(int ac, char **av)
{
	int somme = 0;
	int pointeur = 1;
	int i = strlen(av[1]);
	i--;
	while(i >= 0)
	{
		if(av[1][i] == 49)
		{
			somme += pointeur;
		}
		i--;
		pointeur *= 2;
	}
	printf("%d\n", somme);
}

int main(int ac, char **av)
{
	binToDec(ac, av);
	return(0);
}
