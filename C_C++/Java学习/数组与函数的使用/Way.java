public class Way {
	public static void main( String agrs[] ){
		printof();
		printof();
		printof();
		print2( 2.1f, 3.6f );		//�˴�����ǵ����ȸ����͵����ݣ�����������ݺ���дһ��f����Ȼ���ݻᱻĬ����Ϊ˫����
	}
	public static void printof(){	//�˴���ʹ���޲������ݣ�Ҳ��������������дvoid
		System.out.println("Hello World!!!");
		return ;
	}
	public static void print2( float x, float y ){
		System.out.println( "x + y = " + (x + y ) );
		return ;
	}
}