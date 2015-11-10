#include<stdio.h>

int main(void)
{
    int i,j,flag,k;
    k = 0;
    int a[200]={0};
    for (i=2; i<=1000; i++)
    {
        flag = 1;
        for (j =2; j < i; j++)
            if(i%j==0)
                flag = 0;
        if (flag==1)
        {
            a[k] = i;
            printf("%d,",a[k]);
            k++;
        }
    }
}

