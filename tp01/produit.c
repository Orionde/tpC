#include <stdio.h>
#include <stdlib.h>

void produit()
{
	int a, b = 0;
	printf("Ce programme multiplie deux nombres.\nSaisir un premier nombre : ");
	scanf("%d", &a);
	printf("Saisir un deuxième nombre : ");
	scanf("%d", &b);
	printf("%d x %d = %d\n", a, b, a*b);
}

int main(void)
{
	produit();
	return(0);
}
