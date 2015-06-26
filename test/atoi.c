#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int m_atoi(char *av)
{
	int nombre = 0;
	int i = 0;
	while(av[i])
	{
		nombre *= 10;
		if(isdigit(av[i]))
			nombre += (av[i] - 48);
		else
			break;
		i++;
	}
	return(nombre);
}

int main(int ac, char **av)
{
	if(ac > 1)
		printf("%d\n", m_atoi(av[1]));
	return(0);
}
