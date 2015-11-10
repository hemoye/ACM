public class Sort {
	public static void main( String agrs[] ){
		int score[] = { 66, 99, 21, 42, 100, 50, 60 };
		java.util.Arrays.sort( score );
		for ( int i = 0; i < score.length; i++ )
			System.out.print( score[i] + "¡¢" );
	}
}