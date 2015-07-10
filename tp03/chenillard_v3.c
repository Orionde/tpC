#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char t_inter;

#define ON '*'
#define OFF '.'

void temporisation(int n);
void putstr(char *str);
t_inter inversion(t_inter nb);
void mvLeft(t_inter *inter);
void putRampe(t_inter *rampe);
void initRampe(t_inter inter, t_inter *rampe);

void mvRight(t_inter *inter)
{
	t_inter inter2;
	//t_inter ajout = 1;
	/*while(ajout < sizeof(inter))
	{
		ajout >>= 1;
	}*/
	printf("inter : %d\ninter2 : %d\n\n", *inter, inter2);
	inter2 = *inter;
	*inter >>= 1;
	if(inter2 < *inter)
	{
		*inter += 128;
		printf("+128");
	}
}
void mvLeft(t_inter *inter)
{
	t_inter inter2;
	inter2 = *inter;
	*inter <<= 1;
	if(inter2 > *inter)
	{
		*inter |= 1;
	}
}

void putRampe(t_inter *rampe)
{
	printf("\r%s", rampe);
	fflush(stdout);
	temporisation(250);
}

void initRampe(t_inter inter, t_inter *rampe)
{
	int i = 7;
	int and  = 1; //Ce paramètre servira à faire le et, pour voir quels bits sont à 1.
	int res; //Pour voir si le et fait 0 ou 1;

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
}

t_inter inversion(t_inter nb)
{
	return ~nb;
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
	t_inter inter = 7;
	t_inter rampe[8 * sizeof(inter) + 1] = {0};
	int i = 0;
	while(i < inter)
	{
		//initRampe(inter, rampe);
		//putRampe(rampe);
		mvRight(&inter);
		i++;
	}
	return(0);
}
