class Person {
	int age;
	String name;
	public void show(){
		System.out.println("Name: " + name + ", Age: " + age );
	}
}
public class First {
	public static void main( String agrs[] ){
		Person per1 = new Person();					//对象的声明及实例化
		per1.age = 19;
		per1.name = "莫邪";
		per1.show();
		/*另一种声明、实例化方法：*/
		Person per2 = null;
		per2 = per1;
		per2.age = 18;								//可以实现直接赋值，官方解释为：指向同一片内存区域
		per2.show();								//即将一个堆内存空间的使用权给多个栈内存空间
	}
}
/*声明：
 *	用new是在堆分配内存
 *	而没有使用new的内存空间是在栈里面 
 */