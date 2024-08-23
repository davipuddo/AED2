// 853355 Davi Puddo

public class TP0102
{
	public static String readLine()
	{
		MyIO io = new MyIO();
		return(io.readLine());
	}

	public static void println(String s)
	{
		MyIO io = new MyIO();
		io.println(s);
	}

	// Codificar em cifra de cesar | chave = 3
	public static String encode (String data)
	{
		String result = "";
		if (data != null)
		{
			int n = data.length();
			for (int i = 0; i < n; i++)
			{
				result = result + (char)((int)data.charAt(i) + 3);
			}
		}
		return (result);
	}

	public static void main (String[] args)
	{
		// Definir dados
		String result = null;
		String data = "";
		boolean stop = false;

		while (stop == false)
		{	
			// Ler dados
			data = readLine();
			
			if (data.length() == 3 && data.charAt(0) == 'F' && data.charAt(1) == 'I' && data.charAt(2) == 'M')
			{
				stop = true;
			}

			if (data != null && stop == false)
			{
				// Criptografar dados
				result = encode (data);
				if (result != null)
				{
					// Mostrar dados
					println (result);
				}
			}
		}
	}
}
