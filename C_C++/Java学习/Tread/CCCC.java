class Res
{
	private String name;
	private String sex;
	private boolean flage = false;
	public synchronized void set(String name, String sex)
	{
		if (this.flage)
			try{this.wait();}catch (Exception e){}
		this.name = name;
		this.sex = sex;
		this.flage = true;
		this.notify();
	}
	public synchronized void out()
	{
		if ( !this.flage)
			try{this.wait();}catch (Exception e){}
		System.out.println(name + "-----" + sex );
		this.flage = false;
		this.notify();
	}
}
class Input implements Runnable
{
	private Res r;
	int x = 0;
	Input( Res r )
	{
		this.r = r;
	}
	public void run()
	{
		while ( true )
		{
			if ( x == 0 )
			{
				r.set("mike", "man");
				x = 1;
			}
			else 
			{
				r.set("ľľ", "������");
				x = 0;
			}
		}
	}
}
class Output implements Runnable
{
	private Res r;
	Output( Res r )
	{
		this.r = r;
	}
	public void run()
	{
		while (true)
			r.out();
	}
}
public class CCCC
{
	public static void main( String agrs[] )
	{
		Res r = new Res();
		new Thread( new Input(r) ).start();
		new Thread( new Output(r) ).start();
	}
}