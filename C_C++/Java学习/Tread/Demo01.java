class Demo extends Thread
{
	public void run()
	{
		show();
	}
	public void show(){
		for ( int i = 0; i < 20; i++ )
		{
			System.out.println("i = " + i );
		}
	}
}
public class Demo01
{
	public static void main( String agrs[] ){
		Demo d1 = new Demo();
		Demo d2 = new Demo();
		d1.start();
		d2.start();
	}
}