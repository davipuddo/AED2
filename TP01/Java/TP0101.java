// 853355 Davi Puddo

import java.util.Scanner;

public class TP0101
{
	// Descobrir se uma string e um palindromo
	public static boolean pali (String s)
	{
		boolean result = false;
		if (s != null)
		{
			int i = 0;
			int y = s.length()-1;
			int w = y;
			while (i < w && s.charAt(i) == s.charAt(y))
			{
				y--;
				i++;
			}
			if (i == w)
			{
				result = true;
			}
		}
		return (result);
	}
		
	public static void main (String[] args)
	{
		// Definir dados
		Scanner sc = new Scanner (System.in);
		String data = null;
		boolean result = false;
		boolean stop = false;
		
		while (stop == false)
		{
			// Ler dados
			data = sc.nextLine();
			
			// Verificar existencia de dados
			if (data != null)
			{
				// Verificar se e um palindromo
				result = pali (data);

				// Condicao de parada
				if (data.equals("FIM"))
				{
					stop = true;
				}
				else
				{
					// Mostrar dados
					if (result == true)
					{
						System.out.println ("SI");
					}
					else
					{
						System.out.println ("NAO");
					}
				}
			}
		}
	}
}
