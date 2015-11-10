public class Demo02 {
	public static void main( String agrs[] ){
		System.out.println("******计算开始******");
		int i = 10;
		int j = 2;
		try {
			int temp = i / j;
			System.out.println("i / j = " + temp );
		}catch( ArithmeticException e ){
			System.out.println("出现了异常：" + e );
		}finally {
			System.out.println("不管出没出现异常，最后都执行了该语句！");
		}
		System.out.println("******计算结束******");
	}
}