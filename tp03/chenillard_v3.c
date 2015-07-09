#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

void temporisation(int n);
void putstr(char *str);

unsigned char inversion(unsigned char nb)
{
	return ~nb;
}

void chenillard()
{
	int and  = 1; //Ce paramètre servira à faire le et, pour voir quels bits sont à 1.
	int res; //Pour voir si le et fait 0 ou 1;
	unsigned char inter = 0xAA;
	unsigned char rampe[8 * sizeof(inter) + 1] = {0};
	int i;

	i = 7;
	while(1)
	{
		while(i > -1)
		{
			res = inter & and;
			if(res == and )
				rampe[i] = '*';
			else
				rampe[i] = '.';
			and <<= 1;
			i--;
		}
		printf("\r%s", rampe);
		temporisation(250);
		fflush(stdout);
		i = 7;
		inversion(inter);
	}
}

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

int main(void)
{
	chenillard();
	return(0);
}
