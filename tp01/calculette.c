#include <stdio.h>
#include <stdlib.h>

float calculette(int ac, char **av)
{
	float nb1;
	float nb2;
	char ca;

	if(ac != 1)
	{
		nb1 = atof(av[1]);
		nb2 = atof(av[3]);
		ca = av[2][0];


		if(ca == '+')
			return(nb1 + nb2);
		else if(ca == '-')
			return(nb1 - nb2);
		else if(ca == 'x')
			return(nb1 * nb2);
		else if(ca == '/')
			return(nb1 / nb2);
	}
	return((float) -1);
}

int main(int ac, char **av)
{
	printf("%f\n", calculette(ac, av));
	return(0);
}
