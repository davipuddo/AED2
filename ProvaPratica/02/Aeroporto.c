#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <limits.h>

typedef struct cell_s
{
	char* data;
	struct cell_s* link;
}
Cell;

Cell* newCell (char* x)
{
	Cell* this = (Cell*)malloc(sizeof(Cell));
	if (this)
	{
		this->data = x;
		this->link = NULL;
	}
	return (this);
}

typedef struct Queue_s
{
	Cell* head;
	Cell* tail;
}
Queue;

Queue* newQueue ()
{
	Queue* this = (Queue*)malloc(sizeof(Queue));
	if (this)
	{
		this->head = NULL;
	}
	return (this);
}
	
void insert (Queue* q, char* x)
{
	if (q)
	{
		if (!q->head)
		{
			char* buffer = (char*)calloc(strlen(x)+1,sizeof(char));
			strcpy(buffer, x);
			q->head = newCell(buffer);
			q->tail = q->head;
		}
		else
		{
			char* buffer = (char*)calloc(strlen(x)+1,sizeof(char));
			strcpy(buffer, x);
			Cell* tmp = newCell(buffer);
			q->tail->link = tmp;
			q->tail = tmp;
		}
	}
}

void printR (Cell* ptr)
{
	printf ("%s", ptr->data);
	if (ptr->link)
	{
		printR(ptr->link);
	}
}

void print (Queue* q)
{
	if (q && q->head)
	{
		printR (q->head);
	}
}

typedef struct port_s
{
	Queue* N;
	Queue* S;
	Queue* E;
	Queue* W;
}
Aport;

Aport* newAport ()
{
	Aport* this = (Aport*)malloc(sizeof(Aport));
	if (this)
	{
		this->N = newQueue();
		this->S = newQueue();
		this->E = newQueue();
		this->W = newQueue();
	}
	return (this);
}

void insertN (Aport* a, char* x)
{
	if (a && x)
	{
		insert(a->N, x);
	}
}

void insertS (Aport* a, char* x)
{
	if (a && x)
	{
		insert(a->S, x);
	}
}
void insertE (Aport* a, char* x)
{
	if (a && x)
	{
		insert(a->E, x);
	}
}
void insertW (Aport* a, char* x)
{
	if (a && x)
	{
		insert(a->W, x);
	}
}

Cell* printPos (Queue* q, int pos)
{
	Cell* ptr = NULL;
	if (q && q->head && pos >= 0)
	{
		int i = 0;
		ptr = q->head;
		
		while (ptr->link && i < pos)
		{
			ptr = ptr->link;
			i++;
		}
		if (i == pos)
		{
			printf ("%s ", ptr->data);
		}
		else
		{
			ptr = NULL;
		}
	}
	return (ptr);
}

void printA (Aport* a)
{
	if (a)
	{
		int i = 0;
		int c = 0;
		Cell* ptr = NULL;
		bool stop = false;
		do
		{
			ptr = printPos(a->W, i);
			if (!ptr)
			{
				c++;
			}
			ptr = printPos(a->N, i);
			if (!ptr)
			{
				c++;
			}
			ptr = printPos(a->S, i);
			if (!ptr)
			{
				c++;
			}
			ptr = printPos(a->E, i);
			if (!ptr)
			{
				c++;
			}

			if (c >= 4)
			{
				stop = true;
			}
			else
			{
				c = 0;
			}
			i++;
		} while (stop == false);

		printf("\n");
	}
}

int main (void)
{
	Aport* ap = newAport();
	char* line = (char*)malloc(80*sizeof(char));
	bool stop = false;
	int P = 0;

	while (stop == false)
	{
		scanf (" %s", line);
		getchar();

		if (line[0] == '0')
		{
			stop = true;
		}
		else
		{
			if (line[0] == '-')
			{
				P = line[1] - '0';
				P *= -1;
			}
			else
			{
				if (P == -4)
				{
					insertE(ap, line);
				}
				else if (P == -3)
				{
					insertN(ap, line);
				}
				else if (P == -2)
				{
					insertS(ap, line);
				}
				else if (P == -1)
				{
					insertW(ap, line);
				}
				else
				{
					printf ("ERRO");
				}
			}
		}
	}
	printA(ap);

	return (0);
}
