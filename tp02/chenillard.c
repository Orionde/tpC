#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <time.h>

void temporisation(int n)
{
	clock_t start, stop ;
	n = n*CLOCKS_PER_SEC/1000 ;
	start = clock() ;
	stop = start + n ;
	while(clock() < stop);
}

void putstr(char *str)
{
	while(*str)
		write(1, str++, 1);
}

int main(int ac, char **av)
{
	char a = '*';
	char e = '.';
	int t = 500;
	int n = 10;
	int i = 0;
	if(ac %2 == 1)
	{
		if(ac > 1)
		{
			
			while(i < ac)
			{
				if(av[i][0] == '-')
				{
					if(av[i][0] == 'a')
						a = av[i+1][0];
					if(av[i][0] == 'e')
						e = av[i+1][0];
					if(av[i][0] == 't')
						t = atoi(av[i+1]);
					if(av[i][0] == 'n')
						n = atoi(av[i+1]);
				}
				else
					putstr("erreur");
				i += 2;
			}
		}

		char amp[n];

		for(i = 0; i < n; i++)
			amp[i] = e;

		i = 0;

		while(amp[i])
		{
			amp[i] = a;
			if(i > 0)
				amp[i - 1] = e;
			i++;
			write(1, "\r", 1);
			putstr(amp);
			temporisation(t);
			if(amp[i] == 0)
			{
				amp[i - 1] = e;
				i = 0;
			}
		}
		write(1, "\n", 1);
		return(0);
	}
	else
	{
		putstr("Usage : chenillard_v2 [-a <car_ampoule_allumee>] [-e <car_ampoule_eteinte>] [-t <temporisation>] [-n <nombre_d_ampoules>]");
		write(1, "\n", 1);
	}
	return(1);
}
