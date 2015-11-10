public class 可变参数 {
	public static void main( String agrs[] ){
		System.out.println("不传递参数：");
		fun();
		System.out.println("\n传递1个参数：");
		fun( 1 );
		System.out.println("\n传递5个参数：");
		fun( 1, 2, 3, 4, 5 );
		return ;
	}
	/*可变参数定义格式： 
	 * 	返回值类型   方法名称 （类型。。。参数名称）
	 * */
	public static void fun( int... arg ){
		for ( int i = 0; i < arg.length; i++ )
			System.out.print( arg[i] + "、" );
		return ;
	}
}