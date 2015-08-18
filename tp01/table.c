#include <stdio.h>
#include <stdlib.h>

void table()
{
	int a, i = 1;
	
	printf("Ce programme permet d'afficher une table de multiplication. Entrez un nombre : ");
	scanf("%d", &a);
	while(i < 11)
	{
		printf("%d x %d = %d\n", i, a, a*i);
		i++;
	}
}

int main(void)
{
	table();
	return(0);
}
