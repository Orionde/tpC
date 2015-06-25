#include <stdio.h>
#include <stdlib.h>

void minutesHeures(int *minutes, int *heures)
{
	printf("Minutes vaut : %d\n", *minutes);
	*minutes = *minutes % 60;
	*heures = *minutes / 60;

}

int main(void)
{
	int minutes;
	int heures;

	minutes = 90;
	heures = 0;
	printf("Minutes vaut : %d\n", minutes);
	minutesHeures(&minutes, &heures);

	printf("Il est %d heures et %d minutes\n", heures, minutes);
}
