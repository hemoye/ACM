public class �ɱ���� {
	public static void main( String agrs[] ){
		System.out.println("�����ݲ�����");
		fun();
		System.out.println("\n����1��������");
		fun( 1 );
		System.out.println("\n����5��������");
		fun( 1, 2, 3, 4, 5 );
		return ;
	}
	/*�ɱ���������ʽ�� 
	 * 	����ֵ����   �������� �����͡������������ƣ�
	 * */
	public static void fun( int... arg ){
		for ( int i = 0; i < arg.length; i++ )
			System.out.print( arg[i] + "��" );
		return ;
	}
}