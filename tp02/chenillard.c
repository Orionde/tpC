#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

void check(char *a, char *e, int *t, int *n, int nb, char **str);
void temporisation(int n);
void putstr(char *str);
void chenillard(int nb, char **str)
{

	char a = '*';
	char e = '.';
	int t = 500;
	int n = 10;
	int i;
	if(nb %2 == 1)
	{
		if(nb > 1)
		{
			check(&a, &e, &t, &n, nb, str);
		}
			putchar(str[1][0]);

		char amp[n];

		for(i = 0; i < n; i++)
			amp[i] = e;

		amp[n] = 0;//Ajout du caractère de fin de chaine
		i = 0;

		while(amp[i])
		{
			amp[i] = a;
			if(i > 0)
				amp[i - 1] = e;
			write(1, "\r", 1);
			putstr(amp);
			temporisation(t);
			i++;
			if(amp[i] == 0)
			{
				amp[i - 1] = e;
				i = 0;
			}
		}
		write(1, "\n", 1);
	}
	else
	{
		putstr("Usage : chenillard_v2 [-a <car_ampoule_allumee>] [-e <car_ampoule_eteinte>] [-t <temporisation>] [-n <nombre_d_ampoules>]");
		write(1, "\n", 1);
	}
}

void check(char *a, char *e, int *t, int *n, int nb, char **str)
{
	int i = 1;
	while(i < nb)
	{
		if(str[i][0] == '-')
		{
			if(str[i][1] == 'a')
				*a = str[i+1][0];
			if(str[i][1] == 'e')
				*e = str[i+1][0];
			if(str[i][1] == 't')
				*t = atoi(str[i+1]);
			if(str[i][1] == 'n')
				*n = atoi(str[i+1]);
			if(str[i][1] != 'a' && str[i][1] != 'e' && str[i][1] != 't' && str[i][1] != 'n')
				printf("Argument inconnu : %c", str[i][1]);
		}
		else
			putstr("erreur");
		i += 2;
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

int main(int ac, char **av)
{
	//chenillard(ac, av);
	putchar(av[1][0]);
	return(0);
}
