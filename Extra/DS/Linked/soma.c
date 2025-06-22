#include <stdio.h>
#include <stdlib.h>

typedef struct cell_s
{
	int data;
	struct cell_s* link;
}
Cell;

Cell* newCell (int x)
{
	Cell* this = (Cell*)malloc(sizeof(Cell));
	if (this)
	{
		this->data = x;
		this->link = NULL;
	}

	return (this);
}

typedef struct Q_s
{
	Cell* head;
	Cell* tail;
}
List;

List* newList ()
{
	List* this = (List*)malloc(sizeof(List));
	if (this)
	{
		this->head = NULL;
		this->tail = NULL;
	}
	return (this);
}

// Encapsular metodo
void insertEnd (List* this, int x)
{
	if (this && this->tail)
	{
		Cell* tmp = newCell(x);
		this->tail->link = tmp;
		this->tail = tmp;
		tmp = NULL;
	}
	else if (!this->head)
	{
		this->head = newCell(x);
	}
}

// Encapsular metodo
void insertStart(List* this, int x)
{
	if (this && this->head)
	{
		Cell* tmp = newCell(x);
		if (tmp)
		{
			tmp->link = this->head;
			this->head = tmp;
		}
	}
	else
	{
		this->head = newCell(x);
		this->tail = this->head;
	}
}

void removeStart(List* this)
{
	if (this && this->head)
	{
		Cell* tmp = this->head;
		this->head = tmp->link;
		tmp->link = NULL;
		free(tmp);
	}
	else
	{
		printf ("lista vazia");
	}
}

void removeEndR (Cell* ptr, List* list)
{
	if (ptr->link != list->tail)
	{
		removeEndR(ptr->link, list);
	}
	else
	{
		list->tail = ptr;
		free(ptr->link);
		ptr->link = NULL;
	}
}

void removeEnd (List* this)
{
	if (this)
	{
		if (this->head == this->tail)
		{
			free(this->head);
			free(this->tail);
		}
		else
		{
			removeEndR (this->head, this);
		}
	}
}

int somaR (Cell* ptr, int x)
{
	x = ptr->data;
	if (ptr->link)
	{
		x += somaR(ptr->link, x);
	}

	return (x);
}

int soma (List* this)
{
	int res = 0;
	if (this && this->head)
	{
		res = somaR (this->head, 0);
	}
	return (res);
}

void printC (Cell* ptr)
{
	printf ("%d ", ptr->data);
	if (ptr->link)
	{
		printC (ptr->link);
	}
}

void print (List* this)
{
	if (this && this->head)
	{
		printC (this->head);
		printf ("\n");
	}
}

int main (void)
{
	List* q = newList();
	List* r = NULL;

	insertStart(q, 2);
	insertStart(q, 4);
	insertStart(q, 6);
	insertStart(q, 8);

	r = Div (q);
	
	print(q);
	print(r);

	//printf ("soma: %d\n",soma(q));

	return (0);
}
