class Array {
	private int temp[];
	private int foot;
	public Array( int len ){
		if ( len < 0 ){
			this.temp = new int[1];
		}else {
			this.temp = new int[len];
		}
	}
	public boolean add( int x ){
		if ( this.foot < this.temp.length ){
			this.temp[foot] = x;
			this.foot++;
			return true;
		}else {
			return false;
		}
	}
	public int[] getArray() {
		return this.temp;
	}
}
class ReverseArray extends Array {
	public ReverseArray( int len ){
		super(len);
	}
	public int[] getArray(){
		int t[] = new int[super.getArray().length];
		int count = t.length - 1;
		for ( int x = 0; x < t.length; x++ ){
			t[count] = super.getArray()[x];
			count--;
		}
		return t;
	}
}