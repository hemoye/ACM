import java.io.*;
import java.util.*;
import java.math.BigDecimal;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			BigDecimal r = cin.nextBigDecimal();
			int n = cin.nextInt();
			r = r.pow(n).stripTrailingZeros();     //去掉小数点后面的0
			String m_string = r.toPlainString();   //不带指数段的字符串表示形式
			if (m_string.charAt(0) == '0') m_string = m_string.substring(1);
			System.out.println(m_string);
		}
	}
}