public class String�ĸ��ֲ��� {
	public static void main( String agrs[] ){
		String str1 = "Hello";
		
		char c[] = str1.toCharArray();				//���ַ�������ַ�����ķ���
		for ( int i = 0; i < c.length; i++ ){
			System.out.print(c[i] + "\t" );
		}
		
		System.out.println("");
		String str2 = new String(c);				//���ַ�����ȫ��ת��ΪString
		String str3 = new String( c, 0, 3 );		//�������ַ�����ת��ΪString
		System.out.println(str2);
		System.out.println(str3);
		
		System.out.println( str1.charAt(3) );		//ȡ��String�еĵ��ĸ��ַ�
		System.out.println( "\"" + str1 + "\" �ĳ����ǣ�" + str1.length() );
		
		String str4 = "abcdefgcgh          ";
		System.out.println( str4.indexOf("c"));		//���ַ����в���Ԫ���Ƿ���ڣ������ַ���ʼ����
		System.out.println( str4.indexOf("c", 4 ));	//�ӵ�5���ַ���ʼ����
		System.out.println( str4.indexOf("v"));		//�Ҳ�����Ԫ���򷵻�-1
		System.out.println( str4.trim() );			//ȥ�����ҿո����
	}
}