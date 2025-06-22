class Node
{
	public char data;
	public final int size = 255;
	public Node[] link;
	public boolean leaf;

	public Node (char x)
	{
		this.data = x;
		link = new Node[size];
		for (int i = 0; i < size; i++)
		{
			link[i] = null;
		}
		leaf = false;
	}

	public Node ()
	{
		this(' ');
	}
}

class TRIE
{
	private Node root;

	public TRIE ()
	{
		root = new Node();
	}

	public void insert (String s, Node ptr, int i)
	{
		int pos = (int)s.charAt(i);
		if (ptr.link[pos] == null)
		{
			ptr.link[pos] = new Node (s.charAt(i));

			if (i == s.length() - 1)
			{
				ptr.link[pos].leaf= true;
			}
			else
			{
				insert (s, ptr.link[pos], i + 1);
			}
		}
		else if (ptr.link[pos].leaf == false && i < s.length() - 1)
		{
			insert (s, ptr.link[pos], i + 1);
		}
		else
		{
			System.err.println ("ERROR: Invalid insertion!");
		}
	}

	public void insert (String s)
	{
		insert (s, root, 0);
	}

	public void print (String s, Node ptr)
	{
		if (ptr.leaf)
		{
			System.out.println ("Word:" + (s + ptr.data));
		}
		else
		{
			for (int i = 0; i < ptr.size; i++)
			{
				if (ptr.link[i] != null)
				{
					print (s + ptr.data, ptr.link[i]);
				}
			}
		}
	}

	public void print ()
	{
		print ("", root);
	}

	public boolean search (String s, Node ptr, int i)
	{
		boolean res = false;
		int pos = (int)s.charAt(i);
		if  (ptr.link[pos] != null)
		{
			if (i == s.length() - 1)
			{
				res = (ptr.link[pos].leaf);
			}
			else if (i < s.length() - 1)
			{
				res = search (s, ptr.link[pos], i+1);
			}
			else
			{
				System.err.println("ERROR: Invalid search!");
			}
		}
		return (res);
	}

	public boolean search (String s)
	{
		return (search(s, root, 0));
	}
}

public class Main 
{
	public static void main(String[] args)
	{	
		TRIE t = new TRIE();
		t.insert("car");
		t.insert("carro");
		t.print();
		System.out.println (t.search("casa"));
	}
}
