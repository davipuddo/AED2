public class Main
{
	public static void QueueTest()
	{
		Queue fila = new Queue();
		for (int i = 0; i < 8; i++)
		{
			fila.insert (i+1);
		}

		fila.print();
		System.out.println("\ng:"+fila.get(3));
		System.out.println("");

		fila.remove();
		fila.print();
	}

	public static void StackTest()
	{
		Stack pilha = new Stack();
		for (int i = 0; i < 8; i++)
		{
			pilha.insert(i+1);
		}

		pilha.print();
		System.out.println();
		pilha.remove();
		System.out.println();
		pilha.print();
	}
	
	public static void main(String[] args)
	{	
//		QueueTest();
		StackTest();
	}
}
