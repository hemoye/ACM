public class Demo02 {
	public static void main( String agrs[] ){
		System.out.println("******���㿪ʼ******");
		int i = 10;
		int j = 2;
		try {
			int temp = i / j;
			System.out.println("i / j = " + temp );
		}catch( ArithmeticException e ){
			System.out.println("�������쳣��" + e );
		}finally {
			System.out.println("���ܳ�û�����쳣�����ִ���˸���䣡");
		}
		System.out.println("******�������******");
	}
}