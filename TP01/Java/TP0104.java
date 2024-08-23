// 853355 Davi Puddo

import java.util.*;

public class TP0103
{
	
	public static String randomize (String data, Random ran)
	{
		String result = null;

		if (data != null)
		{
			// Gerar duas letras aleatorias
			char x = (char)(97 + (Math.abs(ran.nextInt()) % 26));
			char y = (char)(97 + (Math.abs(ran.nextInt()) % 26));

			result = "";

			for (int i = 0; i < data.length(); i++)
			{
				if (data.charAt(i) == x)
				{
					result += y;
				}
				else
				{
					result += data.charAt(i);
				}
			}
		}	
		return (result);
	}

	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);	// Obj de leitura
		Random ran = new Random();				// Gerador de numeros aleatorios
		ran.setSeed(4);							// Seed do gerados
		boolean stop = false;					// Condicao de parada
		String result = null;

		while (stop == false)
		{
			String data = sc.nextLine();	// Ler linha
															// Se leitura == FIM				
			if (data.length() == 3 && data.charAt(0) == 'F' && data.charAt(1) == 'I' && data.charAt(2) == 'M')
			{
				stop = true;
			}
			else
			{
				result = randomize(data, ran);

				if (result != null)
				{
					// Mostrar valores
					System.out.println (result);
				}
			}
		}
	}
}
