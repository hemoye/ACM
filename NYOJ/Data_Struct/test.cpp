#include<stdio.h>

int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
/*freopen("test.in", "r", stdin);*/
    int a1,a2,c1,c2,c;
    char o;
    int f,b;
    while(scanf("%d/%d%c%d/%d",&a1,&a2,&o,&c1,&c2)!=EOF)
    {
        b=(a2*c2)/gcd(a2,c2);
        a1=a1*(b/a2);
        c1=c1*(b/c2);
        if(o=='+')
        {
            a1=a1+c1;
        }
        else
            a1=a1-c1;
            if(a1==0) printf("0\n");
            else
            {
               if(a1<0)
               {
                   a1=-a1;
                   printf("-");
               }
                f=gcd(a1,b);
                if(a1==b)   printf("1\n");
                else if (a1 == 0 || b == 1) printf("%d\n", a1);
                else printf("%d/%d\n",a1/f,b/f);
            }

    }

}