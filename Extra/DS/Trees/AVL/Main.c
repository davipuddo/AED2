#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <time.h>

void erro (const char* const x)
{
	printf ("%s :(\n", x);
}

int max (int x, int y)
{
	int res = x;
	if (y > res)
	{
		res = y;
	}
	return (res);
}

typedef struct Cell_s
{
	struct Cell_s* L;
	struct Cell_s* R;
	int data;
	int level;
}
Cell;

Cell* newCell (int x)
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

int getCellLevel (Cell* ptr)
{
	int res = 0;
	if (ptr)
	{
		res = ptr->level;
	}
	return (res);
}

void setCellLevel (Cell* ptr)
{
	int L = getCellLevel(ptr->L);
	int R = getCellLevel(ptr->R);

	ptr->level = max(L,R) + 1;
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

void printCR (Cell* ptr)
{
	if (ptr)
	{
		printCR(ptr->L);
		printf ("%d\n", ptr->data);
		printCR(ptr->R);
	}
}

void printC (AVL* avl)
{
	if (avl)
	{
		printCR(avl->root);
	}
}

void rotL (Cell** ptr)
{
	if (ptr && (*ptr) )
	{
		printf ("rotL\n");
		Cell* newRoot = (*ptr)->R;
		Cell* other = newRoot->L;

		newRoot->R = (*ptr);
		(*ptr)->L = other;

		setCellLevel( (*ptr) );
		setCellLevel(newRoot);

		(*ptr)->L = newRoot;
	}
}

void rotR (Cell** ptr)
{
	if (ptr && (*ptr) )
	{
		printf ("rotR\n");
		Cell* newRoot = (*ptr)->L;
		Cell* other = newRoot->R;
		erro("");


		newRoot->L = (*ptr);
		(*ptr)->R = other;

		setCellLevel( (*ptr) );
		setCellLevel(newRoot);

		(*ptr)->R = newRoot;
	}
}

void balance (Cell** ptr)
{
	if (ptr && (*ptr) )
	{
		int F = getCellLevel( (*ptr)->R) - getCellLevel( (*ptr)->L);
		
		if (F < 2)
		{
			setCellLevel( (*ptr) );
		}
		else if (F == 2)
		{
			int bg = getCellLevel ( (*ptr)->R->R) - getCellLevel( (*ptr)->R->L);

			if (bg == 1)
			{
				rotR( &(*ptr)->R);
			}
			rotL ( &(*ptr)->L);
		}
		else if (F == -2)
		{
			int bg = getCellLevel ( (*ptr)->L->R) - getCellLevel( (*ptr)->L->L);

			if (bg == -1)
			{
				rotR( &(*ptr)->L);
			}
			rotL ( &(*ptr)->R);
		}
	}
}

void insertC (Cell** ptr, int x)
{
	if (ptr)
	{
		if ( !(*ptr) )
		{
			*ptr = newCell(x);
		}
		else if ( (*ptr)->data > x )
		{
			insertC ( &(*ptr)->L, x);
		}
		else if ( (*ptr)->data < x )
		{
			insertC ( &(*ptr)->R, x);
		}
		else
		{
			erro ("isert er");
		}

		balance(ptr);
	}
}

void insert (AVL* avl, int x)
{
	if (avl)
	{
		insertC(&avl->root, x);
	}
	else
	{
		erro("no tre");
	}
}

int main(void)
{
	AVL* avl = newAVL();

	insert(avl, 1);
	insert(avl, 2);
	insert(avl, 3);
	insert(avl, 4);
	insert(avl, 5);
	insert(avl, 6);
	insert(avl, 7);
	printC(avl);
	
	return(0);
}
