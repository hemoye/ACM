#include<stdio.h>

int main(void)
{
    int fac[1000],add[1000];
    int top,n,i,j;
    char ch;

    scanf("%d",&n);

    fac[0]=1;//�������
    add[0]=0;
    for(j=1; j< 1000; j++)
    {
        fac[j]=0;
        add[j]=0;
    }
    top=0;
    for(i=1; i<=n; i++)
    {
        /*�����λ����add*/
        for(j=0; j<=top; j++)
        {
            fac[j]=fac[j]*i;
            if(j==0)
                add[j]=fac[j]/10;
            else
                add[j]=(fac[j]+add[j-1])/10;
        }
        /*����top��ֵ*/
        if(add[top]>=1)
            top++;
        /*����������fac*/
        for(j=0; j<=top; j++)
        {
            if(j==0)
                fac[j]=fac[j]%10;
            else
                fac[j]=(fac[j]+add[j-1])%10;
        }
    }
    /*����������fac*/
    for(j=top; j>=0; j--)
        printf("%d",fac[j]);
    printf("\n");

    return 0;
}
