// Davi Puddo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Util
void println (const char* const x)
{
	if (x)
	{
		printf ("%s\n", x);
	}
}

char* readLine (void)
{	
	char* x = (char*)calloc(301,sizeof(char));
	if (x)
	{
		scanf (" %300[^\n]", x);
		getchar();
	}
	return (x);
}

// Cell
typedef struct cell_s
{
	char data;
	int dx;
	struct cell_s* link;
}
Cell;

Cell* newCell (char x)
{
	Cell* this = (Cell*)malloc(sizeof(Cell));

	if (this)
	{
		this->data = x;
		this->dx = 0;
		this->link = NULL;
	}
	return (this);
}

Cell* NCI (int x)
{
	Cell* this = newCell('0');
	this->dx = x;
	return (this);
}

// Stack
typedef struct stack_s
{
	Cell* head;
}
Stack;

Stack* newStack()
{
	Stack* this = (Stack*)malloc(sizeof(Stack));

	if (this)
	{
		this->head = NULL;
	}
}

void insert (Stack* st, char x)
{
	if (st)
	{
		if (!st->head)
		{
			st->head = newCell(x);
		}
		else
		{
			Cell* tmp = newCell(x);
			if (tmp)
			{
				tmp->link = st->head;
				st->head = tmp;
			}
		}
	}
}

void inserTI (Stack* st, int x)
{
	if (st)
	{
		if (!st->head)
		{
			st->head = NCI(x);
		}
		else
		{
			Cell* tmp = NCI(x);
			if (tmp)
			{
				tmp->link = st->head;
				st->head = tmp;
			}
		}
	}
}

char rmv (Stack* st)
{
	char res = '0';
	if (st && st->head)
	{
		Cell* tmp = st->head;

		res = tmp->data;
		st->head = st->head->link;

		free(tmp);
	}
	return (res);
}

int rmVI (Stack* st)
{
	int res = 0;
	if (st && st->head)
	{
		Cell* tmp = st->head;

		res = tmp->dx;
		st->head = st->head->link;

		free(tmp);
	}
	return (res);
}

void printC (Cell* ptr)
{
	printf ("%c\n", ptr->data);
	if (ptr->link)
	{
		printC(ptr->link);
	}
}

void print (Stack* st)
{
	if (st && st->head)
	{
		printC (st->head);
	}
}

void printD (Cell* ptr)
{
	printf ("%d\n", ptr->dx);
	if (ptr->link)
	{
		printC(ptr->link);
	}
}

void prinD (Stack* st)
{
	if (st && st->head)
	{
		printD (st->head);
	}
}
