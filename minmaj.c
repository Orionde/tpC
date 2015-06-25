#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void minmaj(int ac, char **av)
{
	int min;
	int maj;
	int other;
	int i;
	int j;

	i = 1;
	j = 0;
	min = 0;
	maj = 0;
	other = 0;

	while(i < ac)
	{
		while(j <strlen(av[i]))
		{
			if(av[i][j] >= 'A' && av[i][j] <= 'Z')
				maj++;
			else if(av[i][j] >= 'a' && av[i][j] <= 'z')
				min++;
			else
				other++;
			j++;
		}
		j = 0;
		i++;
	}

	other += ac - 2 ;
	printf("Nombre de majuscules : %d\n", maj);
	printf("Nombre de minuscules : %d\n", min);
	printf("Autre : %d\n", other);
}

int main(int ac, char **av)
{
	minmaj(ac, av);
	return(0);
}
