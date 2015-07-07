#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//------------------------------------------------------------------------------
void Temporisation(int n)
	//------------------------------------------------------------------------------
	// Fonction qui met n milli-secondes a s'executer
	// C'est donc une temporisation de n ms
	// necessite <stdio.h>
{
	clock_t start, stop ;

	n = n*CLOCKS_PER_SEC/1000 ; // clock() ne fonctionne pas forcement en milli-secondes
	start = clock() ;           // Top depart. start = l'heure de depart
	stop = start + n ;          // stop = l'heure de fin

	while(clock() < stop);       // On scrute l'heure tant qu'on n'a pas atteint la fin
}

//------------------------------------------------------------------------------
int main()
	//------------------------------------------------------------------------------
	// petit programme qui teste la fonction Temporisation
{
	int i;
	char tmp;

	//printf("Je compte toutes les secondes jusqu'a 5 :\n") ;
	for (i = 1 ; i < 6 ; i++)
	{
		Temporisation(1000) ;// 1000ms = 1 sec.
		tmp = i + 48;
		write(1, "\r", 1);
		write(1, &tmp, 1);
		//printf("\r%d ",i) ;
		//fflush(stdout) ;
	}
	printf("\nFini !\n") ;

	return EXIT_SUCCESS ;
}

