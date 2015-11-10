import java.math.BigDecimal;
import java.util.Scanner;
 
 
public class Main {
         
        static final int CNT = 6;
        static final int MAX_NUM = 9;
        static final int MAXN = 300+10;
        static final BigDecimal f[][] = new BigDecimal[MAXN][CNT+1];
         
        public static void main(String[] args) {
                Scanner cin = new Scanner(System.in);
                 
                //init.
                for(int i = 0; i <= CNT; i ++) {
                        f[1][i] = BigDecimal.ZERO;
                }
                for(int i = 0; i <= MAX_NUM; i ++) {
                                if( 7 == i ) {
                                        continue;
                                }
                                f[1][i%7] = f[1][i%7].add(BigDecimal.ONE);
                }
                 
                //dp not include 7
                //cur = pre*10+emun type.
                for(int i = 2; i < MAXN; i ++) {
                        for(int j = 0; j <= CNT; j ++) {
                                f[i][j] = BigDecimal.ZERO;
                        }
                        for(int j = 0; j <= CNT; j ++) {
                                for(int k = 0; k <= MAX_NUM; k ++) {
                                        if( 7 == k ) {
                                                continue;
                                        }
                                        f[i][(j*10+k)%7] = f[i][(j*10+k)%7].add(f[i-1][j]);
                                }
                        }
                }
 
                //cal include 7
                int n;
                while( cin.hasNext() ) {
                        n = cin.nextInt();
                        BigDecimal ten, nine;
                        ten = BigDecimal.ONE;
                        nine = BigDecimal.ONE;
                        //this one is cal the number which include 7, 9 jinzhi
                        for(int i = 1; i <= n; i ++) {
                                ten = ten.multiply(BigDecimal.TEN);
                                nine = nine.multiply(new BigDecimal(9));
                        }
                        BigDecimal ans = f[n][0].add(ten.subtract(nine));
                        System.out.println(ans);
                }
        }
}
/**************************************************************
    Problem: 5500
    User: Pascal
    Language: Java
    Result: Accepted
    Time:208 ms
    Memory:21292 kb
****************************************************************/