class A{					// ������A
	public void fun1(){		// ����fun1()����
		System.out.println("A --> public void fun1(){}") ;
	}
	public void fun2(){
		this.fun1() ;		// ����fun1()����
	}
};
class B extends A{
	public void fun1(){		// �˷��������าд��
		System.out.println("B --> public void fun1(){}") ;
	}
	public void fun3(){
		System.out.println("B --> public void fun3(){}") ;
	}
};
public class PolDemo03{
	public static void main(String asrgs[]){
		A a = new A() ;			// ʵ������һ���������
		B b = (B)a ;		// ����������ת�͹�ϵ
		b.fun1() ;
		b.fun2() ;
		b.fun3() ;
	}
};