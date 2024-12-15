#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <time.h>

int max (int x, int y)
{
	int res = x;
	if (y > x)
	{
		res = y;
	}
	return (res);
}

typedef struct Cell_s
{
	int data;
	int lvl;
	struct Cell_s* L;
	struct Cell_s* R;
}
Cell;

Cell* newCell (int x)
{
	Cell* this = (Cell*)malloc(sizeof(Cell));
	if (this)
	{
		this->data = x;
		this->lvl = 1;
		this->L = NULL;
		this->R = NULL;
	}
	return (this);
}

int getLevel (Cell* x)
{
	int res = 0;
	if (x)
	{
		res = x->lvl;
	}
	return (res);
}

void setLevel (Cell* x)
{
	int L = getLevel(x->L);
	int R = getLevel(x->R);
	printf ("old-lvl: %d\n", x->lvl);
	x->lvl = max(L, R) + 1;
	printf ("new-lvl: %d\n", x->lvl);
}

typedef struct AVL_s
{
	Cell* root;
}
AVL;

AVL* newAVL ()
{
	AVL* this = (AVL*)malloc(sizeof(AVL));
	if (this)
	{
		this->root = NULL;
	}
	return (this);
}

void rotR (Cell** ptr)
{
	printf ("rotR\n");
	Cell* newRoot = (*ptr)->L;
	Cell* other = newRoot->R;

	newRoot->R = (*ptr);
	(*ptr)->L = other;

	setLevel( (*ptr));
	setLevel(newRoot);

	*ptr = newRoot;
}

void rotL (Cell** ptr)
{
	printf ("rotL\n");
	Cell* newRoot = (*ptr)->R;
	Cell* other = newRoot->L;

	newRoot->L = (*ptr);
	(*ptr)->R = other;

	setLevel( (*ptr));
	setLevel(newRoot);

	*ptr = newRoot;
}

void balance (Cell** ptr)
{
	if (ptr && (*ptr))
	{
		int F = getLevel( (*ptr)->R) - getLevel( (*ptr)->L);

		if (abs(F) < 2) // F == 0 | 1 | -1
		{
			setLevel (*ptr);
		}
		else if (F == 2)
		{
			int F2 = getLevel( (*ptr)->R->R) - getLevel( (*ptr)->R->L);

			if (F2 == -1)
			{
				rotR( &(*ptr)->R);
			}
			rotL (ptr);
		}
		else if (F == -2)
		{
			int F2 = getLevel ((*ptr)->L->R) - getLevel( (*ptr)->L->L);

			if (F2 == 1)
			{
				rotL ( &(*ptr)->L);
			}
			rotR (ptr);
		}
		else
		{
			printf ("ERRO\nF:%d", F);
		}
	}
}

void insertAVLR (Cell** ptr, int x)
{
	if (ptr)
	{
		if (!(*ptr))
		{
			(*ptr) = newCell(x);
		}
		else if ( (*ptr)->data > x)
		{
			insertAVLR ( &(*ptr)->L, x);
		}
		else if ( (*ptr)->data < x)
		{
			insertAVLR ( &(*ptr)->R, x);
		}
		else
		{
			printf ("ERRO\n");
		}
		balance(ptr);
	}
	else
	{
		printf ("!ptr\n");
	}
}

void insertAVL (AVL* avl, int x)
{
	insertAVLR(&avl->root, x);	
}

void printCR (Cell* ptr)
{
	if (ptr)
	{
		printCR (ptr->L);
		printf ("%d\n", ptr->data);
		printCR (ptr->R);
	}
}

void printC (AVL* avl)
{
	if (avl)
	{
		printCR(avl->root);
		printf ("\n");
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

void printPre (AVL* avl)
{
	if (avl)
	{
		printPreR(avl->root);
		printf ("\n");
	}
}

int main(void)
{
	AVL* avl = newAVL();
	insertAVL(avl, 3);
	insertAVL(avl, 2);
	insertAVL(avl, 1);
	printPre(avl);
	return(0);
}
