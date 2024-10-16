public class Stack
{
	private Cell head;

	Stack ()
	{
		head = new Cell();
	}

	public void insert (int x)
	{
		Cell tmp = new Cell(x, head.link);
		head.link = tmp;
	}

	public int remove ()
	{
		int x = -1;
		if (head.link != null)
		{
			if (head.link.link != null)
			{
				Cell tmp = head.link;
				x = tmp.data;
				head.link = head.link.link;
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
		if (head.link == null)
		{
			System.out.println ("The stack is empty!");
		}
		else
		{
			printC (head.link);
		}
	}
}
