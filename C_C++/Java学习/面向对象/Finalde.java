class A {
	final public void print(){
		
	}
}
class B extends A {
	public void print(){
		
	}
}
//使用final声明的类不能被继承
//使用final声明的函数不能被覆写
//使用final声明的变量就是常量，不可更改，所以应该设置为大写
//使用static final声明的变量就是全局常量