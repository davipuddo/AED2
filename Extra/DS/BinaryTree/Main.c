#include <stdio.h>
#include <stdlib.h>

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

int main (void)
{
	Tree* t = newTree();
	insert(t, 1);
	insert(t, 2);
	insert(t, 3);
	printPre(t);
	rotEsq(t);
	printf ("Rotate-Left:\n");
	printPre(t);
	return (0);
}
