public class StringDe {
	public static void main( String agrs[] ){
		String str1 = "Hello";
		String str2 = "Hello";					//str2��str1ָ��Ķ��ڴ���ͬһ��
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
//������new����ĺ�ֱ�Ӹ�ֵ�Ķ���Hello�����ǱȽϽ����Ȼ�ǲ���...����Ϊ����ͬһ����ڴ��Ե�ʡ�
//����String����ר�ŵıȽϺ���  public boolean eauals( String str )