#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <time.h>

#define ON '*'
#define OFF '.'

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
	int i = 0;
	if(ac > 1)
	{
		while(av[1][i])
		{
			av[1][i] = OFF;
			i++;
		}
		i = 0;
		while(av[1][i])
		{

			av[1][i] = ON;
			if(i > 0)
				av[1][i - 1] = OFF;
			i++;
			write(1, "\r", 1);
			putstr(av[1]);
			temporisation(250);
			if(av[1][i] == 0)
			{
				av[1][i - 1] = OFF;
				i = 0;
			}
		}
		write(1, "\n", 1);

		return(0);
	}
	return(1);
}
