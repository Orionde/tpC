#include <stdlib.h>
#include <stdio.h>

void comptage(int ac, char **av)
{
	char ascii[126] = {0};
	int i = 1;
	int j = 0 ;
	int		c = 0;
	while(i < ac)
	{
		j = 0;
		while(av[i][j])
		{
			c = av[i][j];
			ascii[c] += 1;
			j++;
		}
		i++;
	}
	i = 0;
	while(i < 127)
	{
		if(ascii[i] > 0)
		{
			printf("%c : %d\n", i, ascii[i]);
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
