import java.math.BigDecimal;
import java.util.Scanner;
 
 
public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		BigDecimal down = null;
		int up;
		while( cin.hasNext() ) {
			down = cin.nextBigDecimal();
			up = cin.nextInt();
			down = down.pow(up);
			String ans = down.toPlainString();
			int start = 0, end = ans.length()-1;
			while( ans.charAt(end) == '0' ) {
				end -= 1;
			}
			if( ans.charAt(end) == '.' ) {
				end -= 1;
			}
			while( ans.charAt(start) == '0' ) {
				start += 1;
			}
			for(int i = start; i <= end; i ++) {
				System.out.printf("%c", ans.charAt(i));
			}
			System.out.println();
		}
	}
}
 
/**************************************************************
	Problem: 5497
	User: Pascal
	Language: Java
	Result: Accepted
	Time:196 ms
	Memory:16044 kb
****************************************************************/
