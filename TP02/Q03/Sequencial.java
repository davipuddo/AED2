// 853355 Davi Puddo

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Date;
import java.util.InputMismatchException;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.text.*;

class Pokemon
{

	// Atributos
	private int id;
	private int generation;
	private String name;
	private String description;
	private ArrayList<String> types;
	private ArrayList<String> abilities;
	private double weight;
	private double height;
	private int captureRate;
	private boolean isLegendary;
	private Date captureDate;

	// Construtores
	Pokemon ()
	{
		id = -1;
		generation = -1;
		name = "";
		description = "";
		types = new ArrayList<String> ();
		abilities = new ArrayList<String> ();
		weight = 0.0;
		height = 0.0;
		captureRate = -1;
		isLegendary = false;
		captureDate = new Date();
	}

	Pokemon (int ID, int gen, String Name, String desc, ArrayList<String> type, ArrayList<String> abi, double w, double h, int capRate, boolean leg, Date date)
	{
		this();
		if (name != null && desc != null && type != null && abi != null && date != null)
		{
			id = ID;
			generation = gen;
			name = Name;
			description = desc;
			types = type;
			abilities = abi;
			weight = w;
			height = h;
			captureRate = capRate;
			isLegendary = leg;
			captureDate = date;	
		}
	}

	// Metodos get
	public int getID ()
	{
		return (id);
	}

	public int getGeneration ()
	{
		return (generation);
	}

	public String getName()
	{
		String buffer = "";
		if (name != null)
		{
			buffer = name;
		}
		return (buffer);
	}

	public String getDescription()
	{
		String buffer = "";
		if (description != null)
		{
			buffer = description;
		}
		return (buffer);
	}

	public ArrayList<String> getTypes()
	{
		return (types);
	}

	public ArrayList<String> getAbilities()
	{
		return (abilities);
	}

	public double getWeight ()
	{
		return (weight);
	}

	public double getHeight()
	{
		return (height);
	}

	public int getCaptureRate()
	{
		return (captureRate);
	}

	public boolean getIsLegendary()
	{
		return (isLegendary);
	}

	public Date getCaptureDate()
	{
		return (captureDate);
	}

	// Metodos Set

	public void setID (int x)
	{
		if (x >= 0)
		{
			id = x;
		}
	}

	public void setGeneration (int x)
	{
		if (x >= 0)
		{
			generation = x;
		}
	}

	public void setName (String x)
	{
		if (x != null)
		{
			name = x;
		}
	}

	public void setDescription (String x)
	{
		if (x != null)
		{
			description = x;
		}
	}

	public void setTypes (ArrayList<String> x)
	{
		if (x != null)
		{
			types = x;
		}
	}

	public void setAbilities (ArrayList<String> x)
	{
		if (x != null)
		{
			abilities = x;
		}
	}

	public void setWeight (double x)
	{
		if (x > 0.0)
		{
			weight = x;
		}
	}

	public void setHeight (double x)
	{
		if (x > 0.0)
		{
			height =  x;
		}
	}

	public void setCaptureRate (int x)
	{
		if (x >= 0)
		{
			captureRate = x;
		}
	}

	public void setIsLegendary (boolean x)
	{
		isLegendary = x;
	}

	public void setCaptureDate (Date x)
	{
		if (x != null)
		{
			captureDate = x;
		}
	}

	// Outros metodos

	public Pokemon clone ()
	{
		Pokemon res = new Pokemon (id,generation,name,description,types,abilities,weight,height,captureRate,isLegendary,captureDate);
		return (res);
	}

	public void imprimir ()
	{
		System.out.print ("[#"+id+" -> ");		// id
		System.out.print (name + ": ");			// nome
		System.out.print (description + " - "); // description

		System.out.print ("[");					// types
		for (int i = 0; i < types.size(); i++)
		{
			System.out.print ("'"+types.get(i)+"'");
			if (i < types.size()-1)
			{
				System.out.print (", ");
			}
		}
		System.out.print ("] - ");

		System.out.print ("[");					// abilities
		for (int i = 0; i < abilities.size(); i++)
		{
			System.out.print (""+abilities.get(i)+"");
			if (i < abilities.size()-1)
			{
				System.out.print (", ");
			}
		}
		System.out.print ("] - ");
		
		System.out.print (weight+"kg - ");
		System.out.print (height+"m - ");
		System.out.print (captureRate+"% - ");
		System.out.print (isLegendary+" - ");
		System.out.print (generation+" gen] - ");
		
		SimpleDateFormat sd = new SimpleDateFormat("dd/MM/yyyy");

		System.out.println (sd.format(captureDate));
	}

	public static String[] ler ()
	{
		String[] res = null;
		// Ler arquivo 
		try
		{
			FileReader fr = new FileReader("/tmp/pokemon.csv");
			BufferedReader br = new BufferedReader(fr);

			String[] data = new String[802]; // 801 + primeira linha

			int i = 0;
			while (i < data.length && (data[i] = br.readLine()) != null)
			{
				i++;

			}
			br.close();
			fr.close();
			res = data;	
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
		return (res);
	}

	public void fromList (String poke)
	{
		String[] values = new String[11];
			
		// Separar valores
		int total = 0;
		int i = 0;
		for (total = 0; total < values.length; total++)
		{
			values[total] = "";
			boolean array = false;
			boolean stop = false;

			while (i < poke.length() && stop == false)
			{
				char cur = poke.charAt(i);
				if (total == 4)
				{
					values[total] += cur;

					if (poke.charAt(i+1) == ',')
					{
						if (poke.charAt(i+2) == '"')
						{
							i++;
							stop = true;
						}
						else if (poke.charAt(i+2) == ',')
						{
							i += 2;
							stop = true;	
						}
					}
				}
				else
				{
					if (cur == '[')
					{
						array = true;
					}

					if (array == false && cur == ',')
					{
						stop = true;
					}
					else if (array == true && cur == '"')
					{
						stop = true;
						values[total] += cur;
						i++;
					}

					if (stop == false)
					{
						values[total] += cur;
					}
				}
				i++;
			}
		}

		// Definir id
		if (values[0] != null)
		{
			setID(Integer.parseInt(values[0]));
		}

		// Definir geracao
		if (values[1] != null)
		{
			setGeneration (Integer.parseInt(values[1]));
		}

		// Definir nome
		if (values[2] != null)
		{
			setName (values[2]);
		}

		// Definir descricao
		if (values[3] != null)
		{
			setDescription (values[3]);
		}

		// Definir tipo
		if (values[4] != null)
		{
			String[] buffer = values[4].split(",");
			ArrayList<String> bff = new ArrayList<String>();
			for (int y = 0; y < buffer.length; y++)
			{
				bff.add(buffer[y]);
			}
			setTypes(bff);
		}

		// Corrigir formatacao
		if (values[5] != null)
		{
			String tmp = "";
			for (int y = 0; y < values[5].length(); y++)
			{
				char c = values[5].charAt(y);
				if (c != '"' && c != '[' && c != ']')
				{
					tmp += c;
				}
			}

			// Definir abilidades
			String[] buffer = tmp.split(", ");
			ArrayList<String> bff = new ArrayList<String>();
			for (int y = 0; y < buffer.length; y++)
			{
				bff.add(buffer[y]);
			}
			setAbilities(bff);
		}

		// Definir peso
		if (values[6] != "")
		{
			setWeight(Double.parseDouble(values[6]));
		}

		// Definir altura
		if (values[7] != "")
		{
			setHeight(Double.parseDouble(values[7]));
		}

		// Definir taxa de captura
		if (values[8] != "")
		{
			setCaptureRate (Integer.parseInt(values[8]));
		}

		// Definir se e lendario
		if (values[9] != "")
		{
			boolean buf = false;
			if (values[9].charAt(0) == '1')
			{
				buf = true;
			}
			setIsLegendary(buf);
		}

		// Definir data de captura
		if (values[10] != "")
		{
			SimpleDateFormat sd = new SimpleDateFormat("dd/MM/yy");
			try
			{
				setCaptureDate (sd.parse(values[10]));
			}
			catch (ParseException e)
			{
				e.printStackTrace();
			
			}
		}
	}
}

public class Sequencial
{
	// Dados globais
	static int counter = 0;
	static double start = 0.0;
	static double end = 0.0;

	// Procurar nome na lista de pokemons
	public static boolean find (Pokemon[] poke, String query)
	{
		boolean result = false;
		for (int i = 0; i < poke.length; i++)	 // Counter++
		{
			if (poke[i].getName().equals(query)) // Counter++
			{
				result = true;
			}
			counter++;
		}
		return (result);
	}

	// Gravar tempo de execucao e numero de comparacoes em um arquivo
	private static void printStats()
	{
		// Calcular tempo
		double buffer = ((double)(end-start)/1000000000.0);

		// Abrir arquivo
		try
		{
			PrintWriter w = new PrintWriter("853355-sequencial.txt");
			w.write("853355\t");
			w.write("Tempo de execucao: "+buffer+" ms\t");
			w.write("Numero de comparacoes: "+counter+"\t");
			w.close();
		}
		catch (IOException e)
		{
			System.out.println ("O arquivo nao pode ser aberto!\nERRO:"+e);
			e.printStackTrace();
		}
	}

	public static void main (String[] args)
	{
		// Dados
		Pokemon p = new Pokemon();
		Scanner sc = new Scanner(System.in);
		String[] file = null;
		String[] query = null;
		Pokemon pokes[] = null;
		boolean stop = false;
		String x = null;

		// Ler arquivo
		file = p.ler();

		// Inicializar arrays
		query = new String[25];
		pokes = new Pokemon[51];
			
		// Ler pokemons
		int i = 0;
		while (i < pokes.length && stop == false)
		{
			x = sc.nextLine();
			if (x.equals ("FIM"))
			{
				stop = true;
			}
			else
			{
				// Ler posicao
				String buffer = file[Integer.parseInt(x)];
				pokes[i] = new Pokemon();
				pokes[i].fromList(buffer);
				i++;
			}
		}

		// 
		stop = false;
		i = 0;

		// Ler nomes
		while (i < query.length && stop == false)
		{
			x = sc.nextLine();
			if (x.equals ("FIM"))
			{
				stop = true;
			}
			else if (x != "")
			{
				query[i] = x;
				i++;
			}
		}	
		
		// Procurar nomes
		start = System.nanoTime(); 					// Iniciar contagem de tempo
		for (int y = 0; y < query.length; y++)
		{
			boolean result = find (pokes, query[y]);
			if (result)
			{
				System.out.println ("SIM");
			}
			else
			{
				System.out.println ("NAO");
			}
		}

		// Finalizar contagem de tempo
		end = System.nanoTime();

		// Enviar dados para arquivo
		printStats();
	}
}
