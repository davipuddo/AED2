// 853355 Davi Puddo

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Date;
import java.util.InputMismatchException;
import java.io.*;
import java.text.*;
import java.time.*;

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

class TP
{
	// Elementos globais
	static Instant start;
	static Instant end;
	static int cmp = 0;
	static int mv = 0;

	// Gravar log do programa
	protected static void printStats(String name)
	{
		// Calcular tempo
		double time = (Duration.between(start, end).getNano() / 1000000000.0);

		// Abrir arquivo
		try
		{
			PrintWriter w = new PrintWriter("853355-"+name+".txt");
			w.write("853355");
			w.write("\tTempo de execucao: "+time);
			w.write("\tNumero de comparacoes: "+cmp);
			w.write("\tNumero de movimentacoes: "+mv);
			w.close();
		}
		catch (IOException e)
		{
			System.out.println ("O arquivo nao pode ser aberto!\nERRO:"+e);
			e.printStackTrace();
		}
	}

	public static void swap (int[] array, int x, int y)
	{
		int tmp = array[x];
		array[x] = array[y];
		array[y] = tmp;
		mv++;
	}

	public static void swapPokes (Pokemon[] pokes, int x, int y)
	{
		Pokemon tmp = pokes[x];
		pokes[x] = pokes[y];
		pokes[y] = tmp;
		mv++;
	}
}

class Cell
{
	public Pokemon data;
	public Cell link;

	public Cell (Pokemon x)
	{
		this.data = x;
		this.link = null;
	}

	public Cell ()
	{
		this(null);
	}
}

class Pokedex
{
	private Cell head;
	private Cell tail;
	private int n;

	public Pokedex ()
	{
		this.head = new Cell();
		this.tail = this.head;
		this.n = 0;
	}

	public void insertStart (Pokemon x)
	{
		Cell tmp = new Cell(x);
		tmp.link = this.head.link;
		this.head.link = tmp;
		this.n++;
	}

	public Pokemon removeStart ()
	{
		Pokemon res = null;
		if (this.head != null)
		{
			res = this.head.link.data.clone();
			this.head.link = this.head.link.link;
			this.n--;
		}
		return (res);
	}

	public void insertEnd (Pokemon x)
	{
		if (this.head != null && this.tail != null)
		{
			Cell tmp = new Cell(x);
			if (this.head.link == null)
			{
				this.head.link = tmp;
				this.tail = tmp;
			}
			else
			{
				this.tail.link = tmp;
				this.tail = this.tail.link;
			}
			this.n++;
		}	
	}

	public Pokemon removeEnd ()
	{
		Pokemon res = null;
		if (this.head != null)
		{
			Cell ptr = walk(this.n-1);
			if (ptr != null)
			{
				res = this.tail.data.clone();
				this.tail = ptr;
				this.tail.link = null;
				this.n--;
			}
		}
		return (res);
	}

	private Cell walk (int pos)
	{
		Cell res = null;
		if (pos == 0)
		{
			res = this.head;
		}
		else if (pos > -1)
		{
			Cell ptr = this.head;
			
			int i = 0;
			while (ptr.link != null && i < pos)
			{
				ptr = ptr.link;
				i++;
			}

			if (i == pos)
			{
				res = ptr;
			}
			else
			{
				System.out.println ("Posicao invalida");
			}
		}
		return (res);
	}

	private void print (Cell ptr, int i)
	{
		if (ptr != null)
		{
			System.out.print ("["+i+"] ");
			ptr.data.imprimir();
			print(ptr.link, i+1);
		}
	}

	public void print ()
	{
		if (this.head != null && this.head.link != null)
		{
			print(this.head.link, 0);
		}
		else
		{
			System.out.println ("Pilha vazia");
		}
	}

	public void fromListStart(String line)
	{
		if (line != null)
		{
			Pokemon poke = new Pokemon();
			poke.fromList(line);
			insertStart(poke);
		}
	}

	public void fromListEnd(String line)
	{
		if (line != null)
		{
			Pokemon poke = new Pokemon();
			poke.fromList(line);
			insertEnd(poke);
		}
	}
}

public class PilhaFlex 
{
	public static void main(String[] args)
	{	
		// Definir dados
		Scanner sc = new Scanner(System.in);
		String[] list = Pokemon.ler();
		Pokedex pokes = new Pokedex();
		String line = "";
		boolean stop = false;
		int n = 0;
		int x = 0;

		// Ler pokemons
		while (!stop)
		{
			line = sc.nextLine();

			if (line.equals("FIM"))
			{
				stop = true;
			}
			else
			{
				x = Integer.parseInt(line);
				pokes.fromListEnd(list[x]);
			}
		}

		line = sc.nextLine();
		n = Integer.parseInt(line);

		for (int i = 0; i < n; i++)
		{
			line = sc.nextLine();

			if (line.length() > 2)
			{
				String[] tmp = line.split(" ");
				x = Integer.parseInt(tmp[1]);
				pokes.fromListEnd(list[x]);
			}
			else
			{
				System.out.println ("(R) "+pokes.removeEnd().getName());
			}
		}

		// Mostrar pokemons
		pokes.print();

	}
}
