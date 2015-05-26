#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main()
{
	char c = 0;
	while(c != 'q')
	{
		c = getch();
		printf("%i %c \n",c,c);
	}
	return 0;
}