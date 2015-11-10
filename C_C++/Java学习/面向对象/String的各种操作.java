public class String的各种操作 {
	public static void main( String agrs[] ){
		String str1 = "Hello";
		
		char c[] = str1.toCharArray();				//将字符串变成字符数组的方法
		for ( int i = 0; i < c.length; i++ ){
			System.out.print(c[i] + "\t" );
		}
		
		System.out.println("");
		String str2 = new String(c);				//将字符数组全部转化为String
		String str3 = new String( c, 0, 3 );		//将部分字符数组转化为String
		System.out.println(str2);
		System.out.println(str3);
		
		System.out.println( str1.charAt(3) );		//取出String中的第四个字符
		System.out.println( "\"" + str1 + "\" 的长度是：" + str1.length() );
		
		String str4 = "abcdefgcgh          ";
		System.out.println( str4.indexOf("c"));		//在字符串中查找元素是否存在，从首字符开始查找
		System.out.println( str4.indexOf("c", 4 ));	//从第5个字符开始查找
		System.out.println( str4.indexOf("v"));		//找不到该元素则返回-1
		System.out.println( str4.trim() );			//去掉左右空格输出
	}
}