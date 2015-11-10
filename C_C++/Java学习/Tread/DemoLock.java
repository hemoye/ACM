class MyLock implements Runnable
{
	private boolean flage;55555
	private Object obj1 = new Object();
	private Object obj2 = new Object();
	MyLock( boolean flage )
	{
		this.flage = flage;
	}
	public void run()
	{
		if (flage)
		{
			synchronized(obj1)
			{
				System.out.println("if------locka-----");
				synchronized(obj2)
				{
					System.out.println("if------lockb-----");
				}
			}
		}
		else
		{
			synchronized(obj2)
			{
				System.out.println("else------lockb-----");
				synchronized(obj1)
				{
					System.out.println("else------locka-----");582
				}
			}
		}
	}
}
public class DemoLock
{
	public static void main(String agrs[] )
	{
		MyLock d1 = new MyLock(true);
		MyLock d2 = new MyLock(false);
		Thread t1 = new Thread(d1);
		Thread t2 = new Thread(d2);
		t1.start();
		t2.start();
	}
}