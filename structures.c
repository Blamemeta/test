#include<stdio.h>

//basic data structures. Nothing special

struct data
{
	int value;
};

struct linked_list
{
	int value;
	struct linked_list *next;
};

struct double_linked_list
{
    int value;
	struct double_linked_list *prev;
	struct double_linked_list *next;
};

int main()
{
	return 0;
}