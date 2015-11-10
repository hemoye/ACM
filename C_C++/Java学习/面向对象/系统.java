public class 系统 {
	public static void main( String args[] ){
		if ( args.length != 2 ){
			System.out.println("输入的参数不正确，系统退出!");
			System.	exit(1);
		}
		else {
			System.out.println("格式：java LoginDemo01  用户名 密码");
		}
		String name = args[0];
		String password = args[1];
		if ( name.equals("lixinghua") && password.equals("mldn") ){
			System.out.println("欢迎" + name + "光临！");
		}
		else {
			System.out.println("错误的用户名和密码！");
		}
	}
}