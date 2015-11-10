class Demo implements Runnable
{
	public void run()
	{
		show();
	}
	public void show(){
		for ( int i = 0; i < 20; i++ )
		{
			System.out.println(Thread.currentThread().getName() + "------i = " + i );
		}
	}
}
public class Demo02
{
	public static void main( String agrs[] ){
		Demo d1 = new Demo();
		Thread t1 = new Thread(d1);
		Thread t2 = new Thread(d1);
		t1.start();
		t2.start();
	}
}