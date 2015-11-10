interface A {
	public abstract void print();
} 
class B implements A {
	public void print(){
		System.out.println("Hello World!!!");
	}
}
public class Demo01 {
	public static void main( String agrs[] ){
		B b = new B();
		b.print();
	}
}