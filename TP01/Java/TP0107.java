// 853355 Davi Puddo

import java.io.*;
import java.net.*;
import java.util.Scanner;

public class TP0107
{	
	// Retornar html do site
	public static String getHTML (String link)
	{
		String result = "";
		if (link != null)
		{
			URL url;
			InputStream is = null;
			BufferedReader br;
			String line = "";

			try
			{
				url = new URL (link);
				is = url.openStream();
				br = new BufferedReader(new InputStreamReader(is));

				while ((line = br.readLine()) != null)
				{
					result += line + '\n';
				}
			}
			catch (MalformedURLException mue)
			{
				mue.printStackTrace();
			}
			catch (IOException ioe)
			{
				ioe.printStackTrace();
			}

			try
			{
				is.close();
			}
			catch (IOException ioe)
			{}
		}
		return (result);
	}

	// Retornar TRUE se o caracter for uma letra
	public static boolean isLetter (char c)
	{
		return ( /*(c >= 'A' && c <= 'Z') || */(c >= 'a' && c <= 'z'));
	}

	// Retornar TRUE se o caractere for uma vogal
	public static boolean isVogal (char c)
	{
		return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
	}

	public static boolean isNum (char c)
	{
		boolean result = false;
		if (c >= '0' && c <= '9')
		{
			result = true;
		}
		return (result);
	}

	// Retornar TRUE se o caractere for uma consoante
	public static boolean isConsonant (char c)
	{
		boolean result = false;
		if (isLetter(c) && !isVogal(c) && !isNum(c))
		{
			result = true;
		}
		return (result);
	}

	// Contar valores
	public static int[] count (String data)
	{
		int[] result = null;
		if (data != null)
		{
			// Arranjo de contagem
			result = new int[25];

			if (result != null)
			{
				// Variaveis
				int i = 0;					// Index da string
				int size = data.length();	// Tamanho total da string
				int BSize = size - 5;		// Index do elemento <br>
				int TSize = size - 8;		// Index do elemento <table>

				// Definir contadores para 0
				while (i < 25)
				{
					result[i] = 0;
					i++;
				}
				
				// Contar elementos
				i = 0;
				while (i < size)
				{
					char buffer = data.charAt(i);
					String vogals = "aeiouáéíóúàèìòùãõâêîôû";
					int y = 0;

					// Contar vogais com e sem acento minusculas
					while (y < 22)	
					{
						if (buffer == vogals.charAt(y) /*|| buffer == (char)(vogals.charAt(y) - 32) */)
						{
							result[y] = result[y] + 1;
						}
						y++;
					}
					
					// Contar consoantes
					if (isConsonant(buffer))
					{
						result[22]++;
					}
					
					// Contar elementos <br/>
					if (i < BSize)	
					{
						String br = "<br/>";
						int w = 0;
						
						while (w < 5 && data.charAt(i+w) == br.charAt(w))
						{
							w++;
						}
						if (w == 5)
						{
							result[23]++;
							result[22]--;					// Remover 'b e 'r' do contador de consoantes
						}
					}
					
					// Contar elementos <table>
					if (i < TSize)
					{
						String tb = "<table>";
						int w = 0;

						while (w < 7 && data.charAt(i+w) == tb.charAt(w))
						{
							w++;
						}
						if (w == 7)
						{
							result[24]++;
							result[22] -= 3;			// Remover 't', 'b' e 'l' contador de consoantes
							result[0]--;				// Remover 'a' e 'e' do contador de vogais
							result[1]--;				// 				==
						}
					}
					i++;
				}
			}
		}
		return (result);
	}
	
	public static void main (String[] args)
	{
		String SiteName = "";					// Nome do site
		String URL = null;						// URL do site
		String data = null;						// HTML do site
		Scanner sc = new Scanner(System.in);	// Objeto de leitura
		int [] counter = null;					// Quantidade de valores
		boolean stop = false;					// Condicao de parada

		while (stop == false)
		{
			SiteName = sc.nextLine();
																				// Se entrada == FIM	
			if (SiteName.length() == 3 && SiteName.charAt(0) == 'F' && SiteName.charAt(1) == 'I' && SiteName.charAt(2) == 'M')
			{
				stop = true;
			}
			else
			{
				URL = sc.nextLine();
				data = getHTML(URL);		// Retornar HTML do site

				if (data != null)
				{
					// Contar valores
					counter = count(data);
					
					// Mostrar dados
					String values = "aeiouáéíóúàèìòùãõâêîôû";
					int Vsize = 22;				// = values.length()
					for (int i = 0; i < Vsize; i++)
					{
						System.out.print (values.charAt(i) + "(" + counter[i] + ") ");
					}
					System.out.print ("consoante(" + counter[22] + ") ");
					System.out.print ("<br>(" + counter[23] + ") ");
					System.out.println ("<table>(" + counter[24] + ") " + SiteName);
				}
			}
		}
	}
}
