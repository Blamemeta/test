#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct menuItem
{
	int (*code)(); //ptr to a int function. 
	char * item;
};

struct menu
{
	struct menuItem * items[10];
};

static struct menu main_menu;
static struct menuItem File;
static struct menuItem Options;
static struct menuItem Quit;
static struct menu * cur_menu;
int setColor(int ForgC, int BackC);
int toolBar();
int file();
int quit();
int runCode(char c);

int main ()
{
	char in;
	init();
	
	while(in != 'q')
	{
		system("cls");
		toolBar();
		
		printf(" -> ");
		in = getchar();
		runCode(in);
	}
	return 0;
}

int init()
{
	File.item = "File";
	File.code = &file;
	Options.item = "Options";
	Options.code = &quit;
	Quit.item = "Quit";
	Quit.code = &quit;
	printf("inited");
	main_menu.items[0] = &File;
	main_menu.items[1] = &Options;
	main_menu.items[2] = &Quit;
	printf("inited");
	cur_menu = &main_menu;
	printf("inited");
	return 0;
}

int SetColor(int ForgC, int BackC)
{
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
    return 0;
}

int toolBar()
{
	int index = 0;
	int max = 0;
	SetColor(0xA,0x0);
	char tl[4] = {218,196,196,0};
	char br[4] = {196,196,217,0};
	printf("%s \n",tl);
	while(cur_menu->items[index] != 0 && index < 3)
	{
		printf(" [%i] %s \n",index,cur_menu->items[index]->item);
		if(strlen(cur_menu->items[index]->item) > max)
			max = strlen(cur_menu->items[index]->item);
		index++;
	}
	while(max>0){
		printf(" ");
		max--;
	}
	printf("   %s \n",br);
	SetColor(0xF,0x0);
}

int runCode(char c)
{
	int i = c - '0';
	if(i>9){ return -1; }
	int (*code)();
	code = cur_menu->items[i]->code;
	code();
}

int file(){ system("dir"); getchar(); getchar(); return 0; }

int quit(){ exit(0); return 0; }