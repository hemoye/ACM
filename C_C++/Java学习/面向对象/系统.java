public class ϵͳ {
	public static void main( String args[] ){
		if ( args.length != 2 ){
			System.out.println("����Ĳ�������ȷ��ϵͳ�˳�!");
			System.	exit(1);
		}
		else {
			System.out.println("��ʽ��java LoginDemo01  �û��� ����");
		}
		String name = args[0];
		String password = args[1];
		if ( name.equals("lixinghua") && password.equals("mldn") ){
			System.out.println("��ӭ" + name + "���٣�");
		}
		else {
			System.out.println("������û��������룡");
		}
	}
}