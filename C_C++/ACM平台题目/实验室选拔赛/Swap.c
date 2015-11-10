#include<stdio.h>
#include<string.h>
#include<math.h>

int main(void)
{
    int T,i,j,k;
    long n,m;
    k = 1;
    int a[16],b[16];

    scanf("%d",&T);
    while (T--)
    {
        m = 0;
        scanf("%ld",&n);
        for (i = 0; i < 16; i++)
        {
            a[i] = n%2;
            n /= 2;
        }
        for (i = 0; i < 16; i++)
        {
            b[i] = n%2;
            n /= 2;
        }
        for (i = 15; i >= 0; i--)
            m += a[i]*pow(2,16+i);
        for (i = 15; i >=0; i--)
            m += b[i]*pow(2,i);
        printf("Case %d:\n",k++);
        printf("%ld\n",m);
    }
    return 0;
}
/*
scription

    给出一个小于2^32的正整数（不存在负数）。这个数可以用一个32位的二进制数表示（不足32位用0补足）。我们称这个二进制数的前16位为“高位”，后16位为“低位”。将它的高低位交换，我们可以得到一个新的数。试问这个新的数是多少（用十进制表示）。

Input

一个n（ 1 <= n <= 10^6) ，表示测试数据的数量,接着n行，每一行一个小于2^32

的正整数,处理到文本结束

Output

每组测试数据输出，转换后的十进制数，格式参考样例。

Sample Input

2
12345
1314520
Sample Output

Case 1:
809041920
Case 2:
249036820
HINT
*/
