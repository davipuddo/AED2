public class Queue
{
	private Cell head;
	private Cell tail;

	public Queue()
	{
		head = new Cell();
		tail = head;
	}

	public void insert (int x)
	{
		tail.link = new Cell(x, null);
		tail = tail.link;
	}

	public int remove ()
	{
		int x = -1;
		Cell tmp = head.link;
		if (tmp != null && tmp != tail)
		{
			x = tmp.data;
			if (tmp.link != null)
			{
				head.link = tmp.link;
				tmp = null;
			}
		}
		return (x);
	}

	private void printC (Cell ptr)
	{
		System.out.println (ptr.data);
		if (ptr.link != null)
		{
			printC (ptr.link);
		}
	}

	public void print ()
	{
		printC (head.link);
	}
	
	private int getPosC (Cell ptr, int pos, int i)
	{
		int x = -1;
		if (ptr.link != null)
		{
			if (i == pos)
			{
				x = ptr.data;
			}
			else
			{
				x = getPosC(ptr.link, pos, i+1);
			}
		}
		else
		{
			System.out.println ("Posicao invalida");
		}
		return (x);
	}
	
	public int get (int pos)
	{
		int x = getPosC (head.link, pos, 0);
		return (x);
	}
}
