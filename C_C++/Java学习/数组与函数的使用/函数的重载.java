public class º¯ÊıµÄÖØÔØ {
	public static void main( String agrs[] ){
		add( 1, 2 );
		add( 1.1f, 2.2f );
		add( 1, 2, 3 );
		return ;
	}
	public static void add( int x, int y ){
		System.out.println( x + y );
		return ;
	}
	public static void add( float x, float y ){
		System.out.println( ( x + y ) );
		return ;
	}
	public static void add( int x, int y, int z ){
		System.out.println( ( x + y + z ) );
		return ;
	}
}