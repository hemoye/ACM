interface A {
	public abstract void print();
}
abstract class B {
	public abstract void say();
}
class C extends B implements A {
	public void say(){
		System.out.println("My name is Xie");
	}
	public void print(){
		System.out.println("Hello World!!!");
	}
}
public class Demo02 {
	public static void main( String agrs[] ){
		C c = new C();
		c.print();
		c.say();
	}
}