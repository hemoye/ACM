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
����������������δ�����������һ������Ϊ���ǹȲ��롱�����⣬���������塢��ʮ������������������У��������һʱ��������������������ģ��κ�һ�� ����һ����Ȼ�����������������������ټ�һ�������ż��������Զ����ó��Ľ����������ǰ��Ĺ���������㣬���ض��õ�һ�����������дһ��������֤ ������ȷ�ԡ�



Input

��һ��Ϊ������������N��������N�е���������

Output

�����֤���ǹȲ��롱�����е����������õ���1���������ÿ�����������һ�У�ÿ����ֻ���������֮�������һ���ո����û��������������������No number can be output !��

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
