#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void miroir()
{
	char str[] = "Bonjour";
	char str1[] = "Bonjour";
	int i = strlen(str) - 1;
	int a = 0;
	while(i >= 0)
	{
		str1[a] = str[i];
		a++;
		i--;
	}
	printf("%s\n", str1);

}

int main(void)
{
	miroir();
	return(0);
}
