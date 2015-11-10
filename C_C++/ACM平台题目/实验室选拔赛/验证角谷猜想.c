#include<stdio.h>

int main(void)
{
    int i,T,n,k,flag;
    k = 1;
    scanf("%d",&T);
    while (T--)
    {
        flag = 0;
        scanf("%d",&n);
        printf("Case %d:\n",k++);
        while (n!=1)
        {
            if (n%2!=0)
            {
                flag++;
                printf(flag==1?"%d":" %d",n);
            }
            if (n%2==0)
                n /= 2;
            else
                n = n*3+1;
        }
        if (flag==0)
            printf("No number can be output !");
        printf("\n");
    }
    return 0;
}
/*
数论中有许多猜想尚未解决，其中有一个被称为“角谷猜想”的问题，该问题在五、六十年代的美国多个著名高校中曾风行一时，这个问题是这样描述的：任何一个 大于一的自然数，如果是奇数，则乘以三再加一；如果是偶数，则除以二；得出的结果继续按照前面的规则进行运算，最后必定得到一。现在请你编写一个程序验证 他的正确性。



Input

第一行为测试数据组数N，接着是N行的正整数。

Output

输出验证“角谷猜想”过程中的奇数，最后得到的1不用输出；每个测试题输出一行；每行中只有两个输出之间才能有一个空格；如果没有这样的输出，则输出：No number can be output !。

Sample Input

4
5
9
16
11
Sample Output

Case 1:
5
Case 2:
9 7 11 17 13 5
Case 3:
No number can be output !
Case 4:
11 17 13 5
*/
