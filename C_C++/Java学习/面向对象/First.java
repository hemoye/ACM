class Person {
	int age;
	String name;
	public void show(){
		System.out.println("Name: " + name + ", Age: " + age );
	}
}
public class First {
	public static void main( String agrs[] ){
		Person per1 = new Person();					//�����������ʵ����
		per1.age = 19;
		per1.name = "Īа";
		per1.show();
		/*��һ��������ʵ����������*/
		Person per2 = null;
		per2 = per1;
		per2.age = 18;								//����ʵ��ֱ�Ӹ�ֵ���ٷ�����Ϊ��ָ��ͬһƬ�ڴ�����
		per2.show();								//����һ�����ڴ�ռ��ʹ��Ȩ�����ջ�ڴ�ռ�
	}
}
/*������
 *	��new���ڶѷ����ڴ�
 *	��û��ʹ��new���ڴ�ռ�����ջ���� 
 */