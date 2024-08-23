// 853355 Davi Puddo

public class TP0110
{
	// Descobrir se e um palindromo
	public static boolean palin (String data, int i)
	{
		boolean result = false;
		if (data != null)
		{
			int size = data.length()-1;
			
			result = (data.charAt(i) == data.charAt(size-i));

			if (i < (int)((double)size/2.0))
			{
				result = (result && palin(data, i+1));
			}
		}
		return (result);
	}

	public static void main (String[] args)
	{
		// Definir dados
		boolean stop = false;
		boolean result = false;
		String data = null;

		while (stop == false)
		{
			// Ler dados
			data = MyIO.readLine();

			// Condicao de parada: data == FIM
			if (data != null && data.length() == 3 && data.charAt(0) == 'F' && data.charAt(1) == 'I' && data.charAt(2) == 'M')
			{
				stop = true;
			}
			else
			{
				// Descobrir se e um palindromo
				result = palin (data, 0);

				// Mostrar resultado
				if (result)
				{
					System.out.println ("SIM");
				}
				else
				{
					System.out.println ("NAO");
				}
			}
		}
	}
}
