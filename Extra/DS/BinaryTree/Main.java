class Cell
{
	protected int data;
	protected Cell L;
	protected Cell R;

	public Cell (int x, Cell l, Cell r)
	{
		data = x;
		L = l;
		R = r;
	}

	public Cell (int x)
	{
		this(x, null, null);
	}

	public Cell ()
	{
		this(0);
	}
}

class Tree
{
	public void println (String line)
	{
		System.out.println (line); 
	}

	public Cell root;

	public Tree ()
	{
		root = null;
	}

	private Cell insert (Cell ptr, int x)
	{
		if (ptr == null)
		{
			ptr = new Cell(x);
		}
		else if (x < ptr.data)
		{
			ptr.L = insert(ptr.L, x);
		}
		else if (x > ptr.data)
		{
			ptr.R = insert(ptr.R, x);
		}
		else
		{
			try
			{
				throw new Exception ("Erro ao inserir o valor: " + x);
			}
			catch (Exception e)
			{
				e.printStackTrace();
			}
		}
		return (ptr);
	}

	public void insert (int x)
	{
		root = insert(root, x);
	}

	private Cell search (Cell ptr, int x)
	{
		Cell res = null;
		if (ptr != null)
		{
			if (x == ptr.data)
			{
				res = ptr;
			}
			else if (x < ptr.data)
			{
				res = search (ptr.L, x);
			}
			else
			{
				res = search (ptr.R, x);
			}
		}
		return (res);
	}

	public Cell search (int x)
	{
		return (search(root, x));
	}

	private Cell sbR (Cell ptr, int x)
	{
		Cell res = null;
		if (ptr != null)
		{
			if (x < ptr.data)
			{
				if (ptr.L != null)
				{
					if (ptr.L.data == x)
					{
						res = ptr;
					}
					else if (x < ptr.L.data)
					{
						res = sbR (ptr.L.L, x);
					}
					else
					{
						res = sbR (ptr.L.R, x);
					}
				}
			}
			else if (x > ptr.data)
			{
				if (ptr.R != null)
				{
					if (ptr.R.data == x)
					{
						res = ptr;
					}
					else if (x < ptr.R.data)
					{
						res = sbR (ptr.R.L, x);
					}
					else
					{
						res = sbR (ptr.R.R, x);
					}
				}
			}
			else
			{
				println ("Erro!");
			}
		}
		return (res);
	}

	public Cell searchBefore (int x)
	{
		return(sbR(root, x));
	}

	// Remove um no qualquer da arvore
	private void removePos (int x)
	{
		Cell b = searchBefore(x);
		if (b != null)
		{
			Cell tmp = b.L;
			if (tmp != null)
			{
				if (tmp.data != x)
				{
					tmp = b.R;
				}

				if (tmp.L == null && tmp.R == null)
				{
					if (b.L == tmp)
					{
						b.L = null;
					}
					else
					{
						b.R = null;
					}
					tmp = null;
				}
				else if (tmp.L != null)
				{
					if (b.L == tmp)
					{
						b.L = tmp.L;
					}
					else
					{
						b.R = tmp.L;
					}
					tmp = null;
				}
				else if (tmp.R != null)
				{
					if (b.L == tmp)
					{
						b.L = tmp.R;
					}
					else
					{
						b.R = tmp.R;
					}
					tmp = null;
				}
			}	
		}
	}

	// Retorna o menor valor de uma subarvore
	private int small (Cell ptr)
	{
		int res = 0;
		if (ptr != null && ptr.L != null)
		{
			res = small(ptr.L);	
		}
		else if (ptr.L == null)
		{
			res = ptr.data;
		}
		return (res);
	}

	// Retorna o valor do menor no da arvore
	public int smallest ()
	{
		int res = 0;
		if (root != null)
		{
			res = small(root);
		}
		return (res);
	}

	// Remove a raiz da arvore
	private void removeRoot ()
	{
		// Encontrar menor no a direita
		int sm = small(root.R);

		// Encontrar no anterior ao menor
		Cell abv = searchBefore(sm);
		Cell x = null;

		if (abv != null)
		{
			if (abv != root)	// Se o no anterior e diferente da raiz
			{
				x = abv.L;

				if (x.R != null)
				{
					abv.L = x.R;
				}
				x.R = root.R;
			}
			else				// Se for igual
			{
				x = abv.R;
				if (x.R != null)
				{
					abv.R = x.R;
				}
			}
			x.L = root.L;

			root.L = null;
			root.R = null;

			root = x;
		}
	}

	// Remover um no da arvore
	public void remove (int x)
	{
		if (root != null)
		{
			if (root.data != x)
			{
				removePos(x);	
			}
			else
			{
				removeRoot();
			}
		}
	}

	private void PC (Cell ptr)
	{
		if (ptr != null)
		{
			PC(ptr.L);
			System.out.println (ptr.data);
			PC(ptr.R);
		}
	}

	public void printCenter ()
	{
		PC(root);
		println ("");
	}

	private void PPre (Cell ptr)
	{
		if (ptr != null)
		{
			System.out.println (ptr.data);
			PC(ptr.L);
			PC(ptr.R);
		}
	}

	public void printPre ()
	{
		PPre(root);
		println ("");
	}

	private void PPos (Cell ptr)
	{
		if (ptr != null)
		{
			PC(ptr.L);
			PC(ptr.R);
			System.out.println (ptr.data);
		}
	}

	public void printPos ()
	{
		PPos (root);
		println ("");
	}
}

public class Main
{
	public static void main (String[] args)
	{
		// Definir dados
		Tree x = new Tree();
		Cell c = null;

		// Inserir
		x.insert(3);
		x.insert(2);
		x.insert(1);
		x.insert(5);
		x.insert(6);
		x.insert(7);

		// Procurar
		c = x.search(3);
		System.out.println ("Valor "+c.data+" encontrado em: "+c);

		// Remover
		x.remove(2);
		x.remove(1);

		// Prints
		System.out.println ("\nCenter:"); 
		x.printCenter();

		System.out.println ("Pre:"); 
		x.printPre();

		System.out.println ("Pos:"); 
		x.printPos();
	}
}
