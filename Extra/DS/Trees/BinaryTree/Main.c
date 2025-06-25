#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// === Estruturas === //


// Celula

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

// Arvore

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
	return (this);
}

// === Metodos === //

// Insercao para celula 
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

// Insercao para arvore
void insert (Tree* tree, int x)
{
	if (tree)
	{
		insertC(&tree->root, x);
	}
	else
	{	
		printf ("Erro: Arvore Nula\n");
	}
}

// === Metodos caminhar === //

// Caminhar centro esquerda recursiva
void printCLr (Cell* ptr)
{
	if (ptr)
	{
		printCLr(ptr->L);
		printf ("%d\n", ptr->data);
		printCLr(ptr->R);
	}
}

// Caminhar centro direita recursiva
void printCRr (Cell* ptr)
{
	if (ptr)
	{
		printCRr(ptr->R);
		printf ("%d\n", ptr->data);
		printCRr(ptr->L);
	}
}

// Caminhar centro esquerda
void printCL (Tree* tree)
{
	if (tree)
	{
		printCLr(tree->root);
	}
}

// Caminhar centro direita 
void printCR (Tree* tree)
{
	if (tree)
	{
		printCRr(tree->root);
	}
}

// Caminar pos recursiva
void printPosR (Cell* ptr)
{
	if (ptr)
	{
		printPosR(ptr->L);
		printPosR(ptr->R);
		printf ("%d\n", ptr->data);
	}
}

// Caminar pos
void printPos (Tree* tree)
{
	if (tree)
	{
		printPosR(tree->root);
	}
}

// Caminar pre recursiva
void printPreR (Cell* ptr)
{
	if (ptr)
	{
		printf ("%d\n", ptr->data);
		printPreR(ptr->L);
		printPreR(ptr->R);
	}
}

// Caminhar pre
void printPre (Tree* tree)
{
	if (tree)
	{
		printPreR(tree->root);
	}
}

// === Metodos Rotacao === //

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

// Calcular altura //

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

// Contar numero de nos

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

// Ler input
int readInt ()
{
	int x = 0;
	scanf (" %d", &x);
	getchar();
	return (x);
}


int main (void)
{
	// Criar arvore
	Tree* t = newTree();
	
	int x = 0;
	bool stop = false;

	// inserir valores na arvore
	printf("inserir valores: (x!=0)\n\n");
	while (!stop)
	{
		printf("valor = ");
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

	// Chamar metodos

	c = 0;
	count(t->root);
	printf ("\ncontador: %d\n", c);

	printf ("\nCaminhar Arvore\n\nCentro Esq:\n");
	printCL(t);

	printf ("\nCentro Dir:\n");
	printCR(t);

	printf ("\nPos:\n");
	printPos(t);
	
	printf ("\nPre:\n");
	printPre(t);

	printf("\nRotacionar Arvore\n");
	rotEsq(t);

	printf ("\nCaminhar Arvore\n\nCentro Esq:\n");
	printCL(t);

	printf ("\nCentro Dir:\n");
	printCR(t);

	printf ("\nPos:\n");
	printPos(t);
	
	printf ("\nPre:\n");
	printPre(t);


	return (0);
}
