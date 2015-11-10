class Ticket implements Runnable
{
	private int num = 200;
	private Object obj = new Object();
	public void run()
	{
		while ( true )
		{
			this.sale();
		}
	}
	public synchronized void sale()
	{
		if ( num > 0 )
		{
			try
			{
				Thread.sleep(100);
			}
			catch ( Exception e )
			{
				e.printStackTrace();
			}
			System.out.println( Thread.currentThread().getName() + "=====ÂôÆ±£º" + num-- );
		}
	}
}
public class DemoFunction
{
	public static void main( String agts[] )
	{
		Ticket d = new Ticket();
		Thread t1 = new Thread(d);
		Thread t2 = new Thread(d);
		Thread t3 = new Thread(d);
		t1.start();
		t2.start();
		t3.start();
	}
}