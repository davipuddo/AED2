public class Cell
{
	public int data;
	public Cell link;

	public Cell()
	{
		this.data = -1;
		this.link = null;
	}

	public Cell(int x, Cell l)
	{
		this.data = x;
		this.link = l; 
	}

	public void setData (int x)
	{
		this.data = x;
	}

	public void setLink (Cell l)
	{
		this.link = l;
	}

	public int getData ()
	{
		return (this.data);
	}

	public Cell getLink ()
	{
		return (this.link);
	}	
}
