// 853355 Davi Puddo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define null NULL

// Metodos gerais
void println (char* x)
{
	if (x)
	{
		printf ("%s\n", x);
	}
}

char* readLine ()
{
	char* buffer = (char*)calloc(301,sizeof(char));
	if (buffer)
	{
		scanf (" %300[^\n]", buffer);
		getchar();
	}
	return (buffer);
}

int readInt()
{
	int x = 0;
	scanf (" %d", &x);
	getchar ();
	return (x);
}

// Converter string para int
int parseInt(char* data)
{
	int result = 0;
	if (data)
	{
		int size = (int)strlen(data);
		for (int i = 0; i < size; i++)
		{
			int buffer = data[i] - '0';
			result += buffer * pow(10,(size-i-1));
		}
	}
	return (result);
}

// Converter string para double
double parseDouble (char* data)
{
	double result = 0.0;
	if (data)
	{
		int size = (int)strlen(data);
		double buffer = 0.0;
		bool dc = false;
		
		int y = 0;
		while (y < size && data[y] != '.' && data[y] != ',') // Encontar virgula
		{
			y++;
		}

		if (y > 0)
		{
			y--;
		}
		
		for (int i = 0; i < size; i++)
		{
			if ((i < size-1)&& (data[i] == '.' || data[i] == ','))
			{
				dc = true;
				i++;
			}

			buffer = data[i] - '0';
			if (!dc)				// Acima da virgula
			{
				result += (buffer * pow(10,(y-i)));
			}
			else					// Abaixo
			{
				result += (buffer / pow(10,(i-y-1)));
			}
		}

	}
	return (result);
}

// Converter uma string para valor booleano
bool parseBool (char* data)
{
	bool result = false;
	if (data)
	{
		if (data[0] == '1' || strcmp(data, "true") == 0 || strcmp(data, "TRUE") == 0)
		{
			result = true;
		}
	}
	return (result);
}

void freeString (char** data, int n)
{
	if (data)
	{
		for (int i = 0; i < n; i++)
		{
			free (data[i]);
		}
		free(data);
	}
}

// Lista
typedef struct list_s
{
	char** data;
	int n;
	int length;
}
List;

// Alocar lista
List* newList (int size, int rowSize)
{
	List* list = (List*)malloc(sizeof(List));

	if (list)
	{
		list->length = 0;
		list->n = 0;
		list->data = NULL;

		if (size > 0)
		{
			list->length = size;
			list->data = (char**)calloc((size+1),sizeof(char*));

			if (list->data)
			{
				for (int i = 0; i < size; i++)
				{
					list->data[i] = (char*)calloc(rowSize,sizeof(char));
					list->data[i][0] = '*';
				}
			}
			else
			{
				println ("Falta de espaco!");
			}
		}
	}
	else
	{
		println ("Falta de espaco!");
	}
	return (list);
}

// Clonar lista
List* cloneList (List* list)
{
	List* res = false;
	if (list)
	{
		// Criar nova lista
		res = newList(list->n, 160);

		if (res)
		{
			// Copiar dados
			for (int i = 0; i < list->n; i++)
			{
				strcpy(res->data[i], list->data[i]);
			}
		}
	}
	return (res);
}

void freeList (List* list)
{
	for (int i = 0; i < list->length; i++)
	{
		free(list->data[i]);
	}
	free(list->data);
	free(list);
}

// Inserir na lista
void insertL (List* list, char* x, int pos)
{
	if (list && x && list->n >= pos && pos >= 0)
	{
		if (list->n < list->length)
		{
			for (int i = list->n; i > pos; i--)
			{
				list->data[i] = list->data[i-1];
			}
			strcpy(list->data[pos], x);
			list->n++;
		}
		else
		{
			println ("A lista esta cheia");
		}
	}
	else
	{
		println ("Dados invalidos!");
	}
}

// Encapsular metodo de inserir no fim
void insert (List* list, char* x)
{
	insertL (list, x, list->n);
}

// Remover da lista
void removeL (List* list, int pos)
{
	if (list && pos > 0 && list->n >= pos)
	{
		for (int i = pos; i < list->n; i++)
		{
			list->data[i] = list->data[i+1];
		}
		list->n--;
	}
	else
	{
		println ("Dados invalidos!");
	}
}

// Encapsular metodo de remover no fim
void Remove (List* list)
{
	if (list)
	{
		removeL (list, list->n);
	}
}

// Printar lista
void printL (List* list)
{
	if (list)
	{
		for (int i = 0; i < list->n; i++)
		{
			int size = strlen(list->data[i]);

			for (int y = 0; y < size; y++)
			{
				printf ("%c", list->data[i][y]);
			}
			println("");
		}
	}
	else
	{
		println ("Dados invalidos!");
	}
}

// Pokemon
typedef struct poke_s
{
	int id;
	int generation;
	char* name;
	char* description;
	List* types;
	List* abilities;
	double weight;
	double height;
	int captureRate;
	bool isLegendary;
	char* date;
}
Pokemon;

// Construtor sem parametros
Pokemon* newPokemon ()
{
	Pokemon* poke = (Pokemon*)malloc(sizeof(Pokemon));

	if (poke)
	{
		poke->id = -1;
		poke->generation = -1;
		poke->name = (char*)calloc(16,sizeof(char));
		poke->description = (char*)calloc(64,sizeof(char));
		poke->types = newList(3,40);
		poke->abilities = newList(6,40);
		poke->weight = 0.0;
		poke->height = 0.0;
		poke->captureRate = 0;
		poke->isLegendary = false;
		poke->date = (char*)calloc(9,sizeof(char));	// "dd/mm/yy" + \0
	}
	return (poke);
}

// Construtor com parametros
Pokemon* newPokemonWith (int ID, int gen, char* name, char* des, List* type, List* abili, double w, double h, int cRate, bool L, char* d)
{
	Pokemon* poke = newPokemon();
	if (poke && ID >= 0 && gen > 0 && name && des && type && abili && w > 0.0 && h > 0.0 && cRate >= 0 && d)
	{	
		poke->id = ID;
		poke->generation = gen;
		poke->name =  name;
		poke->description = des;
		poke->types = type;
		poke->abilities = abili;
		poke->weight = w;
		poke->height = h;
		poke->captureRate = cRate;
		poke->isLegendary = L;
		poke->date = d;
	}
	return (poke);
}

void freePoke (Pokemon* poke)
{
	if (poke)
	{
		free(poke->name);
		free(poke->description);
		freeList(poke->types);
		freeList(poke->abilities);
		free(poke->date);
	}
}

Pokemon* clone (Pokemon* other)
{
	Pokemon* res = NULL;
	if (other)
	{
		res = newPokemon();
		if (res)
		{
			res->id = other->id;
			res->generation = other->generation;
			strcpy (res->name, other->name);
			strcpy (res->description, other->description);
			res->types = cloneList(other->types);
			res->abilities = cloneList(other->abilities);
			res->weight = other->weight;
			res->height = other->height;
			res->captureRate = other->captureRate;
			res->isLegendary = other->isLegendary;
			strcpy (res->date, other->date);
		}
		else
		{
			println ("Dados invalidos!");
		}
	}
	else
	{
		println ("Dados invalidos!");
	}
	return (res);
}

// Ler arquivo csv
List* ler ()
{
	List* result = NULL;
	FILE* file = fopen ("/tmp/pokemon.csv", "rt");
	if (file)
	{
		result = newList(802,160);
		if (result)
		{
			int i = 0;									// Nao usei o metodo insert porque o resultado estava errado
			while (fgets (result->data[i], 160, file))	// mesmo com o metodo funcionando. Ele ficava com o valor
			{											// da ultima linha depois de sair do while, se eu acessase
				int n = strlen(result->data[i])-1;		// os dados dentro do while funcionava normal. Nao sei o que
				result->data[i][n] = '\0';				// esta errado :)
				i++;
			}
			result->n = i;
			fclose(file);
		}
		else
		{
			println ("Falta de espaco!");
		}
	}
	else
	{
		println ("Arquivo nao pode ser aberto!");
	}
	return (result);
}

// Printar elementos do objeto
void imprimir (Pokemon* poke)
{
	if (!poke)
	{
		println ("Dados invalidos!");
	}
	else
	{
		printf ("[#%d -> %s: %s - [",poke->id,poke->name,poke->description);
		for (int i = 0; i < poke->types->n; i++)
		{
			printf ("'%s'",poke->types->data[i]);
			if (i < poke->types->n - 1)
			{
				printf (", ");
			}
		}

		printf ("] - [");
		for (int i = 0; i < poke->abilities->n; i++)
		{
			printf ("'%s'", poke->abilities->data[i]);
			if (i < poke->abilities->n - 1)
			{
				printf (", ");
			}
		}
		printf ("] - %.1lfkg - %.1lfm - %d%% - ", poke->weight, poke->height, poke->captureRate);

		char* buffer = "false";
		if (poke->isLegendary)
		{
			buffer = "true";
		}
		printf ("%s - %d gen] - ", buffer, poke->generation);

		for (int i = 0; i < 10; i++)
		{
			printf ("%c", poke->date[i]);
		}
		println ("");
	}
}

// Ler linha do arquivo e criar um novo objeto
Pokemon* fromLine (char* data)
{	
	Pokemon* result = NULL;

	if (data)
	{
		char** values = (char**)malloc(11*sizeof(char*));

		for (int i = 0; i < 11; i++)
		{
			values[i] = (char*)calloc(20,sizeof(char));
		}

		if (values)
		{
			// Copiar valores de data
			char* copy = (char*)calloc((int)strlen(data)+1,sizeof(char));
			strcpy (copy, data);
			
			/* Separar valores */

			// id-gen-name-desc
			char* token = NULL;
			int i = 0;
			token = strtok (copy, ",");	
			while (i < 3 && token != NULL)
			{
				values[i] = token;
				token = strtok (NULL, ",");
				i++;
			}
			values[i] = token;
			i++;

			// Tipos
				// Limpar saida
			token = strtok(NULL, "\"");
			if (token[strlen(token)-2] == ',')
			{
				token[strlen(token)-2] = '\0';
			}
			else
			{
				token[strlen(token)-1] = '\0';
			}
			values[i] = token;
			i++;
	
			// peso - altura - captura - lendario - data
			token = strtok (NULL, "\"");
			values[i] = token;
			i++;

			// Altura
			token = strtok (NULL, "");
			if (token[1] != ',')
			{
				token = strtok(token, ",");
				values[i] = token;
			}
			i++;
		
			// Peso
			if (token[2] != ',')
			{
				token = strtok(NULL, ",");
				values[i] = token;
			}
			i++;
			
			// Captura - lendario - data
			if (token[0] == ',')
			{
				token = strtok(token, ",");
				values[i] = token;
				i++;
			}

			while (i < 11 && token != NULL)
			{
				token = strtok(NULL, ", ");	
				values[i] = token;
				i++;
			}

			/* Criar obj */

			result = newPokemon();
			result->id = parseInt(values[0]);
			result->generation = parseInt(values[1]);
			result->name = values[2];
			result->description = values[3];

			// Corrigir tipos
			token = strtok(values[4], ",");

			while (token != NULL)
			{
				insert(result->types, token);
				token = strtok(NULL, ",");
			}

			// Corrigir abilidade
			token = strtok(values[5], "['");

			while (token != NULL)
			{
				if (token[0] != ' ')
				{
					insert(result->abilities, token);
				}
				token = strtok(NULL, "',]");
			}

			// Peso - altura - chance - lendario - data
			result->weight = parseDouble(values[6]);
			result->height = parseDouble(values[7]);
			result->captureRate = parseInt(values[8]);
			result->isLegendary = parseBool(values[9]);	
			result->date = values[10];
		}
		else
		{
			println ("Falta de espaco!");
		}
	}
	else
	{
		println ("Dados invalidos!");
	}

	return (result);
}

Pokemon* fromList (List* list, int pos)
{
	char* tmp = NULL;
	Pokemon* poke = NULL;

	if (list && pos >= 0)
	{
		if (pos < list->n)
		{
			tmp = list->data[pos];
			poke = fromLine(tmp);
		}
	}
	return (poke);
}

// Dados estaticos
static int cmp = 0;
static int mv = 0;
static clock_t start;
static clock_t end;

typedef struct poke_cell_s
{
	Pokemon* data;
	struct poke_cell_s* front;
	struct poke_cell_s* back;
}
Cell;

// "Construtor" de celula
Cell* newCell (Pokemon* poke)
{
	Cell* this = NULL;
	this = (Cell*)malloc(sizeof(Cell));

	if (this)
	{
		this->data = NULL;
		this->front = NULL;
		this->back = NULL;
		
		if (poke)
		{
			this->data = poke;
		}
	}
	else
	{
		println ("Falta de espaco!");
	}

	return (this);
}

// Liberar celulas da memoria
void freeCell (Cell* c)
{
	if (c)
	{
		if (c->front)
		{
			freeCell (c->front);
		}
		free(c);
	}
}

// Pokedex (Lista de Pokemons)
typedef struct pokedex_s
{
	Cell* head;
	Cell* tail;
	int n;
}
Pokedex;

// "Construtor" da pokedex
Pokedex* newPokedex (void)
{
	Pokedex* this = (Pokedex*)malloc(sizeof(Pokedex));
	if (this)
	{
		this->head = newCell(NULL);
		this->tail = this->head;
		this->n = 0;
	}
	else
	{
		println ("Falta de espaco!");
	}

	return (this);
}

// Liberar pokedex da memoria
void freeDex (Pokedex* dex)
{
	if (dex)
	{
		if (dex->head)
		{
			freeCell(dex->head);
		}
		free(dex);
	}
}

// Percorrer lista encapsulada
Cell* walk (Pokedex* dex, int pos)
{
	Cell* ptr = NULL;
	if (dex && dex->head && dex->tail)
	{
		if (dex->head->front)
		{
			if (pos < dex->n)
			{
				int m = (dex->n/2.0);
				if (pos <= m)
				{
					ptr = dex->head->front;	
					int i = 0;
					while (ptr && i < pos)
					{
						ptr = ptr->front;
						i++;
						cmp+=2;
						mv++;
					}
				}
				else
				{
					ptr = dex->tail;
					int i = dex->n-1;
					while (ptr && i > pos)
					{
						ptr = ptr->back;
						i--;
						cmp+=2;
						mv++;
					}
				}

				if (!ptr)
				{
					println ("vazia");
				}
				cmp += 3;
			}
			else
			{
				println ("Posicao invalida");
			}
			cmp++;
		}
		else
		{
			println ("Dex vazia");
		}
		cmp++;
	}
	else
	{
		println ("Dados invalidos");
	}
	cmp++;
	return (ptr);
}

void insertDexStart (Pokedex* dex, Pokemon* poke)
{
	if (dex && dex->head && poke)
	{
		Cell* tmp = newCell(poke);

		tmp->front = dex->head->front;
		if (tmp->front)
		{
			tmp->front->back = tmp;
		}
		tmp->back = dex->head;
		dex->head->front = tmp;

		if (dex->tail == dex->head)
		{
			dex->tail = tmp;
		}
	}
	else
	{
		println ("Dados invalidos");
	}
}

// Inserir pokemon no fim
void insertDexEnd (Pokedex* dex, Pokemon* poke)
{
	if (dex && dex->head && dex->tail && poke)
	{
		Cell* tmp = newCell(poke);
		tmp->back = dex->tail;
		dex->tail->front = tmp;
		dex->tail = tmp;
		dex->n++;
	}
	else
	{
		println ("Dados invalidos!");
	}
}

// Remover pokemon do inicio
Pokemon* removeDexStart (Pokedex* dex)
{
	Pokemon* res = NULL;
	if (dex && dex->head)
	{
		if (dex->head->front)
		{
			res = clone(dex->head->front->data);
			Cell* ptr = dex->head->front;
			ptr->back = NULL;
			dex->head->front = ptr->front;
			ptr->front = NULL;
			free(ptr);
		}
		else
		{
			println ("Dex vazia");
		}
	}
	else
	{
		println ("Dados invalidos");
	}
	return (res);
}

// Mostrar pokemons
void printDexR (Cell* ptr, int i)
{
	if (ptr)
	{
		printf ("[%d] ", i);
		imprimir(ptr->data);

		if (ptr->front)
		{
			printDexR(ptr->front, i+1);
		}
	}
}

// Encapsular metodo de print
void printDex(Pokedex* dex)
{
	if (dex)
	{
		printDexR(dex->head->front, 0);
	}
}

void printBackR (Cell* ptr)
{
	imprimir(ptr->data);

	if (ptr->back)
	{
		printBackR (ptr->back);
	}
}

void prinB (Pokedex* dex)
{
	if (dex)
	{
		printBackR (dex->tail);
	}
}

void swapPokes (Pokedex* dex, int px, int py)
{
	if (dex)
	{
		cmp++;
		Cell* x = walk(dex, px);
		Cell* y = walk(dex, py);

		if (x && y)
		{
			cmp++;
			Pokemon* tmp = x->data;
			x->data = y->data;
			y->data = tmp;
			mv++;
		}
	}
}

void qs (Pokedex* dex, int L, int R)
{
	int tmp = ((L+R)/2.0);
	Pokemon* pivo = walk(dex, tmp)->data;
	int pg = pivo->generation;
	char* pn = pivo->name;
	int i = L;
	int y = R;

	while (i <= y)
	{
		cmp++;
		while (walk(dex, i)->data->generation < pg || ( walk(dex, i)->data->generation == pg && strcmp(walk(dex, i)->data->name, pn) < 0) )
		{
			i++;
			cmp+=3;
		}
		while (walk(dex, y)->data->generation > pg || ( walk(dex, y)->data->generation == pg && strcmp(walk(dex, y)->data->name, pn) > 0) )
		{
			y--;
			cmp+=3;
		}
		if (i <= y)
		{
			swapPokes (dex, i, y);
			i++;
			y--;
			cmp++;
		}
	}
	
	if (i < R)
	{
		qs (dex, i, R);
		cmp++;
	}
	if (y > L)
	{
		qs (dex, L, y);
		cmp++;
	}
}

void QuickSort(Pokedex* dex)
{
	if (dex)
	{
		qs (dex, 0, dex->n-1);
		cmp++;
	}
}

// Gravar arquivo log
void printStats (char* filename)
{
	if (!filename)
	{
		println ("Nome de arquivo inexistente!");
	}
	else
	{
		FILE* file = fopen (filename, "wt");

		if (!file)
		{
			println ("O arquivo nao pode ser aberto!");
		}
		else
		{
			double time = ((double)(end-start)/CLOCKS_PER_SEC);
			fprintf (file, "853355\t%lf\t%d\t%d", time, cmp, mv); 
			fclose (file);	
		}
	}
}

int main (void)
{
	// Definir dados
	List* list = ler();
	Pokedex* dex = newPokedex();
	char* line = NULL;
	int x = 0;
	int i = 0;
	int n = 0;
	bool stop = false;

	// Ler ids
	while (stop == false) 
	{
		// Ler entrada
		line = readLine();

		if (line)
		{
			// Condicao de parada
			if (strcmp(line, "FIM") == 0)
			{
				stop = true;			
			}
			else
			{
				// Inserir pokemon
				x = parseInt(line);
				Pokemon* poke = fromList(list, x);
				insertDexEnd (dex, poke);
			}
		}
		else
		{
			stop = true;
			println ("Dados inexistentes");
		}
	}

	// Ordenar Lista
	QuickSort (dex);

	// Liberar csv
	freeList(list);

	// Mostrar resultado
	printDex (dex);

	// Liberar pokedex
	freeDex(dex);

	// Gravar arquivo log
	printStats("853355_quicksort2");

	return(0);
}
