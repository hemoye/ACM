public class StringDe {
	public static void main( String agrs[] ){
		String str1 = "Hello";
		String str2 = "Hello";					//str2与str1指向的堆内存是同一个
		String str3 = new String("Hello");
		String str4 = str2;
		System.out.println( str1 == str2 );
		System.out.println( str3 == str2 );
		System.out.println( str3.equals(str2) );
		System.out.println( str4 == str2 );
		System.out.println( str1.equals( str3 ) );
		System.out.println( str1 == str3 );
	}
}
//明明用new分配的和直接赋值的都是Hello，但是比较结果竟然是不等...是因为不在同一块堆内存的缘故。
//于是String有了专门的比较函数  public boolean eauals( String str )