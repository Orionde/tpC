#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

void temporisation(int n);
void putstr(char *str);

void chenillard(int nb)
{
	int and  = 1; //Ce paramètre servira à faire le et, pour voir quels bits sont à 1.
	int res; //Pour voir si le et fait 0 ou 1;
	unsigned char inter = 10;
	unsigned char rampe[] = "********";
	int i;

	/*for(i = 0; i < 8; i++)
	{
		rampe[i] = '1';
	}*/
	//putstr(rampe);

	i = 7;
	while(i > -1)
	{
		res = inter & and;
		if(res == and )
		{	
			rampe[i] = '*';
			//printf("* : %d\n",i);
		}
			
		else
		{
			rampe[i] = '.';
			//printf(". : %d\n",i);
		}


		and <<= 1;
		i--;
	}
	printf("\n%s\n", rampe);


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
	chenillard(8);
	return(0);
}
