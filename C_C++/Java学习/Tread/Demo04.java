class MyThread implements Runnable
{
	public void run()
	{
		for ( int i = 0; i < 5; i++ )
		{
			System.out.println( Thread.currentThread().getName() + "----i = " + i );
			try
			{
				Thread.sleep(10000);
			}
			catch ( Exception e )
			{
				System.out.println(e);
			}
		}
	}
}
public class Demo041408
{
	public static void main( String agrs[] )
	{
		MyThread my = new MyThread();
		Thread t1 = new Thread( my, "线程A");
		Thread t2 = new Thread( my, "线程B");
		t1.start();
		t2.start();
	}
}