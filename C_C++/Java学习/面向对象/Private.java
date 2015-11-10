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
		/*另一种输入方法
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
		per1.setname( "莫邪" );
		per1.show();
		Person per2 = new Person( "张三", 19 );
		per2.show();
		new Person( "李四", 20 ).show(); 				//匿名对象，不使用栈内存引用
	}
}