#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char a[5]= "aaaaa";
	int i = 0;
	while(i < 6)
	{
		a[i] = '5';
		i++;
		printf("%s\n", a);
	}
	return(0);
}
