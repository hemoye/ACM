public class 把数组作为函数返回值 {
	public static void main( String agrs[] ){
		int arrAy[] = New();
		for ( int i = 0; i < arrAy.length; i++ )
			System.out.print( arrAy[i] + "、" );
	}
	public static int[] New(){					//这里突破了c、c++的限制可以直接把数组作为函数的返回值
		int s[] = { 1, 3, 5, 6, 7 };
		return s;
	}
}