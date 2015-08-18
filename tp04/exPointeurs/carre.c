#include <stdio.h>
#include <stdlib.h>

int carre1(int a)
{
	return(a*a);
}

void carre2(int *a)
{
	*a = *a * *a;
}

int main(void)
{
	int a = 5;
	int b = 5;
	printf("%d\n", carre1(a));
	carre2(&b);
	printf("%d\n", b);
	return(0);
}
