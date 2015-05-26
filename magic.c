#include<stdio.h>
#include<windows.h>

//contains all of my old magic methods. 

int p(char *str);
int SetColorAndBackground(int ForgC, int BackC);

int main()
{
	char *str = "Hello, World";
	p(str);
	p("Hello, World");
	
	SetColorAndBackground(0xA,0x0);
	p("Hello, World");
	SetColorAndBackground(0xB,0x0);
	p("Hello, World");
	SetColorAndBackground(0xC,0x0);
	p("Hello, World");
	SetColorAndBackground(0xD,0x0);
	p("Hello, World");
	SetColorAndBackground(0xE,0x0);
	p("Hello, World");
	SetColorAndBackground(0xF,0x0);
	p("Hello, World");
	
	return 0;
}

int p(char *str)
{
	printf("%s\n",str);
}

int SetColorAndBackground(int ForgC, int BackC)
{
	//0xA is Bright Green
	//0xB is Bright Blue
	//0xC is Bright Red
	//0xD is Bright Purple
	//0xE is Bright Yellow
	//0xF is White
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
    return 0;
}