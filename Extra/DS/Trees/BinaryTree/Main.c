#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Cell_s
{
	int data;
	struct Cell_s* L;
	struct Cell_s* R;
}
Cell;

Cell* newCell(int x)
{
	Cell* this = (Cell*)malloc(sizeof(Cell));
	if (this)
	{
		this->data = x;
		this->L = NULL;
		this->R = NULL;
	}
	return (this);
}

typedef struct Tree_s
{
	Cell* root;
}
Tree;

Tree* newTree()
{
	Tree* this = (Tree*)malloc(sizeof(Tree));
	if (this)
	{
		this->root = NULL;
	}
}

void insertC (Cell** ptr, int x)
{
	if (!(*ptr))
	{
		*ptr = newCell(x);	
	}
	else if (x < (*ptr)->data)
	{
		insertC(&(*ptr)->L, x);
	}
	else if (x > (*ptr)->data)
	{
		insertC(&(*ptr)->R, x);
	}
	else
	{
		printf ("Erro\n");
	}
}

void insert (Tree* tree, int x)
{
	if (tree)
	{
		insertC(&tree->root, x);
	}
	else
	{	
		printf ("n\n");
	}
}

void printCr (Cell* ptr)
{
	if (ptr)
	{
		printCr(ptr->L);
		printf ("%d\n", ptr->data);
		printCr(ptr->R);
	}
}

void printC (Tree* tree)
{
	if (tree)
	{
		printCr(tree->root);
	}
}

void printPosR (Cell* ptr)
{
	if (ptr)
	{
		printPosR(ptr->L);
		printPosR(ptr->R);
		printf ("%d\n", ptr->data);
	}
}

void printPos (Tree* tree)
{
	if (tree)
	{
		printPosR(tree->root);
	}
}

void printPreR (Cell* ptr)
{
	if (ptr)
	{
		printf ("%d\n", ptr->data);
		printPreR(ptr->L);
		printPreR(ptr->R);
	}
}

void printPre (Tree* tree)
{
	if (tree)
	{
		printPreR(tree->root);
	}
}

void rotEsqC (Cell** ptr)
{
	Cell* ptrR = (*ptr)->R;
	Cell* ptrRL = ptrR->L;

	ptrR->L = (*ptr);
	(*ptr)->R = ptrRL;

	*ptr = ptrR;
}

void rotEsq (Tree* tree)
{
	if (tree)
	{
		rotEsqC (&tree->root);
	}
}

static int max;

int getHeightC (Cell* ptr, int x)
{
	if (ptr)
	{
		int L = getHeightC(ptr->L, x+1);
		int R = getHeightC(ptr->R, x+1);

		if (x < L)
		{
			x = L;
		}
		if (x < R)
		{
			x = R;
		}
	}
	return (x);
}

int getHeight (Tree* t)
{
	int x = 0;
	if (t)
	{
		max = 0;
		x = getHeightC(t->root, 0);
	}
	return (x);
}

int readInt ()
{
	int x = 0;
	scanf (" %d", &x);
	getchar();
	return (x);
}

static int c;

void count(Cell* ptr)
{
	if (ptr)
	{
		count(ptr->L);
		count(ptr->R);
		c++;
	}
}

int main (void)
{
	Tree* t = newTree();
	
	int x = 0;
	bool stop = false;

	while (!stop)
	{
		x = readInt();
		if (x != 0)
		{
			insert(t, x);
		}
		else
		{
			stop = true;
		}
	}
	c = 0;
	count(t->root);
	printf ("c:%d\n ", c);
	printf ("\n");
	printC(t);

	return (0);
}
