#include<stdio.h>
#include<windows.h>

int SetColorAndBackground(int ForgC, int BackC);

int main()
{
	char input;
	system("dir");
	return 0;
}

int SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return 0;
}

