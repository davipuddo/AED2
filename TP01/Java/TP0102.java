// 853355 Davi Puddo

import java.util.Scanner;

public class TP0102
{
	// Codificar em cifra de cesar | chave = 3
	public static String encode (String data)
	{
		String result = "";
		if (data != null)
		{
			int n = data.length();
			int buffer = 0;
			for (int i = 0; i < n; i++)
			{
				buffer = (int)data.charAt(i) + 3;
				result = result + (char)buffer;
			}
		}
		return (result);
	}

	public static void main (String[] args)
	{
		// Definir dados
		Scanner sc = new Scanner(System.in);
		String result = null;
		String data = "";

		while (!data.equals("FIM"))
		{	
			// Ler dados
			data = sc.nextLine();

			if (data != null && !data.equals("FIM"))
			{
				// Criptografar dados
				result = encode (data);
				if (result != null)
				{
					// Mostrar dados
					System.out.println (result);
				}
			}
		}
		sc = null;
	}
}
