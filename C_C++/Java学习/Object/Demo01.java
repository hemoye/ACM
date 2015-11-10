class Demo extends Object {
	
}
public class Demo01 {
	public static void main( String agrs[] ){
		Demo d = new Demo();
		System.out.println("不加toString()输出：" + d );
		System.out.println("加上toString()输出：" + d.toString() );
	}
}