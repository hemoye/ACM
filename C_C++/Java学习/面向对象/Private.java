class Person {
	private String name;
	private int age;
	public void show(){
		System.out.println("Name: " + Getname() + " Age: " + Getage() );
	}
	public Person(){}
	public Person( String na, int n ){
		name = na;
		age = n;
		/*��һ�����뷽��
		 * 	this.setname( na );
			this.setage( n );
		 * */
	}
	public void setname( String n ){
		name = n;
	}
	public void setage( int n ){
		if ( n < 0 || n > 140 )	age = 0;
		else	age = n;
	}
	public String Getname(){
		return name;
	}
	public int Getage(){
		return age;
	}
}
public class Private {
	public static void main( String agrs[] ){
		Person per1 = new Person();
		per1.show();
		per1.setage( 19 );
		per1.setname( "Īа" );
		per1.show();
		Person per2 = new Person( "����", 19 );
		per2.show();
		new Person( "����", 20 ).show(); 				//�������󣬲�ʹ��ջ�ڴ�����
	}
}