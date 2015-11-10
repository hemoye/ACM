public class Way {
	public static void main( String agrs[] ){
		printof();
		printof();
		printof();
		print2( 2.1f, 3.6f );		//此处如果是单精度浮点型的数据，则必须在数据后面写一个f，不然数据会被默认问为双精度
	}
	public static void printof(){	//此处即使是无参数传递，也不能在括号里面写void
		System.out.println("Hello World!!!");
		return ;
	}
	public static void print2( float x, float y ){
		System.out.println( "x + y = " + (x + y ) );
		return ;
	}
}