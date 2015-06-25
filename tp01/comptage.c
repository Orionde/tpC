#include <stdlib.h>
#include <stdio.h>

void comptage(int ac, char **av)
{
	char ascii[127] = {0};
	int i = 1;
	int j = 0 ;
	int compteur = 1;
	char c;

	while(compteur < ac)
	{
		while(av[i][j])
		{
			char c = av[i][j];
			ascii[c] += 1;
			j++;
		}
		compteur ++;
	}
	i = 0;
	while(ascii[i])
	{
		if(ascii[i] > 0)
		{
			printf("%c : %d", ascii[i], ascii[i]);
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if(ac > 1)
	{
		comptage(ac, av);
		return(0);
	}
	return(1);
}
