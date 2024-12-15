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

class NodeX
{
	public String name;
	public NodeX L;
	public NodeX R;

	public NodeX (String x)
	{
		this.L = null;
		this.R = null;
		this.name = x;
	}

}

class TreeX
{
	private NodeX root;

	public TreeX ()
	{
		this.root = null;
	}

	private NodeX insert (NodeX ptr, String x)
	{
		if (ptr == null)
		{
			ptr = new NodeX(x);
		}
		else if (ptr.name.compareTo(x) > 0)
		{
			ptr.L = insert(ptr.L, x);
			TP.cmp++;
		}
		else if (ptr.name.compareTo(x) < 0)
		{
			ptr.R = insert(ptr.R, x);
			TP.cmp++;
		}
		else
		{
			System.out.println ("ERRO");
		}
		TP.cmp++;
		return (ptr);
	}

	public void insert (String x)
	{
		this.root = insert(this.root, x);
	}

	private boolean search (NodeX ptr, String x)
	{
		boolean res = false;
		if (ptr != null)
		{
			if (ptr.name.equals(x))
			{
				res = true;
			}
			else if (ptr.name.compareTo(x) > 0)
			{
				System.out.print ("esq ");
				res = search(ptr.L, x);
				TP.cmp++;
			}
			else if (ptr.name.compareTo(x) < 0)
			{
				System.out.print ("dir ");
				res = search(ptr.R, x);
				TP.cmp++;
			}
			TP.cmp++;
		}
		TP.cmp++;
		return (res);
	}

	public boolean search (String x)
	{
		boolean res = false;
		if (x != null)
		{
			res = search(this.root, x);
		}
		TP.cmp++;
		return (res);
	}

}

class NodeY
{
	public int cRate;
	public NodeY L;
	public NodeY R;
	public TreeX other;

	public NodeY (int x)
	{
		this.L = null;
		this.R = null;
		this.cRate = x;
		this.other = new TreeX ();
	}
}

class TreeY
{
	private NodeY root;

	public TreeY ()
	{
		this.root = null;
	}

	private NodeY insertNum (NodeY ptr, int x)
	{
		if (ptr == null)
		{
			ptr = new NodeY(x);
		}
		else if (x < ptr.cRate)
		{
			ptr.L = insertNum(ptr.L, x);
			TP.cmp++;
		}
		else if (x > ptr.cRate)
		{
			ptr.R = insertNum(ptr.R, x);
		}
		TP.cmp++;
		return (ptr);
	}

	public void insertNum (int x)
	{
		this.root = insertNum(this.root, x);
	}

	private NodeY insertPoke (NodeY ptr, int x, String name)
	{
		if (ptr == null)
		{
			ptr = new NodeY (x);
			ptr.other.insert(name);
			TP.cmp++;
		}
		else if (x < ptr.cRate)
		{
			ptr.L = insertPoke(ptr.L, x, name);
			TP.cmp++;
		}
		else if (x > ptr.cRate)
		{
			ptr.R = insertPoke(ptr.R, x, name);
			TP.cmp++;
		}
		else
		{
			ptr.other.insert(name);
		}
		TP.cmp++;
		return (ptr);
	}

	public void insertPoke (int cRate, String name)
	{
		if (name != null)
		{
			this.root = insertPoke(this.root, cRate, name);
			TP.cmp++;
		}
	}

	public boolean search (NodeY ptr, String name)
	{
		boolean res = false;
		if (ptr != null)
		{
			res = ptr.other.search(name);
			if (!res)
			{
				System.out.print (" ESQ ");
				res = search(ptr.L, name);
			}
			if (!res)
			{
				System.out.print (" DIR ");
				res = search(ptr.R, name);
			}
			TP.cmp += 2;
		}
		TP.cmp++;
		return (res);
	}

	public boolean search (String name)
	{
		boolean res = false;
		if (name != null)
		{
			System.out.println ("=> "+name);
			System.out.print ("raiz ");
			res = search(this.root, name);
		}
		TP.cmp++;
		return (res);
	}

	public void insertS ()
	{
		this.insertNum (7);
		this.insertNum (3);
		this.insertNum (11);
		this.insertNum (1);
		this.insertNum (5);
		this.insertNum (9);
		this.insertNum (13);
		this.insertNum (0);
		this.insertNum (2);
		this.insertNum (4);
		this.insertNum (6);
		this.insertNum (8);
		this.insertNum (10);
		this.insertNum (12);
		this.insertNum (14);
	}

	public void fromList (int pos)
	{
		if (pos > 0)
		{
			String line = Pokemon.ler()[pos];
			Pokemon poke = new Pokemon();
			poke.fromList(line);
			insertPoke (poke.getCaptureRate() % 15, poke.getName());
		}
		TP.cmp++;
	}
}

public class ArvoreArvore
{
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		TreeY dex = new TreeY();
		String line = "";
		boolean stop = false;

		TP.start = Instant.now();

		dex.insertS();

		while (stop == false)
		{
			line = sc.nextLine();

			if (line.equals("FIM"))
			{
				stop = true;
			}
			else
			{
				int x = Integer.parseInt(line);
				
				dex.fromList(x);
			}
			TP.cmp += 2;
		}
		TP.cmp++;
		
		stop = false;

		while (stop == false)
		{
			line = sc.nextLine();

			if (line.equals("FIM"))
			{
				stop = true;
			}
			else
			{
				boolean res = dex.search(line);
				if (res)
				{
					System.out.println (" SIM");
				}
				else
				{
					System.out.println (" NAO");
				}
				TP.cmp++;
			}
			TP.cmp += 2;
		}
		TP.cmp++;

		TP.end = Instant.now();
		TP.printStats("arvoreArvore");
	}
}

