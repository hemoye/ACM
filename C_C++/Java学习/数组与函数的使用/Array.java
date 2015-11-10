public class Array {
	public static void main( String agrs[] ){
		int arrAy[] = new int [10];					//一维数组的声明方法
		for ( int i = 0; i < arrAy.length; i++ )	arrAy[i] = i + 1;
		for ( int i = 0; i < arrAy.length; i++ )
			System.out.println("arrAy["+i+"]=" + arrAy[i] );
		int arr[][] = new int[4][3];				//二维数组的声明方法
		for ( int i = 0; i < arr.length; i++ ){
			for ( int j = 0; j < arr[i].length; j++ ){
				arr[i][j] = i * 10 + j;
			}
		}
		for ( int i = 0; i < arr.length; i++ ){
			for ( int j = 0; j < arr[i].leng; j++ ){
				System.out.print( arr[i][j] + "\t" );
			}
			System.out.println("");
		}
	}
}