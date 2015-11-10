#include <stdio.h>
#include <stdlib.h>
int main()
{
    freopen("test.in", "r", stdin);
    int a[10],i,j,t,x;
    for(i=0; i<10; i++)
        scanf("%d",&a[i]);
    for(i=0; i<10; i++)
    {
        x=i;
        for(j=i+1; j<10; j++)
            if(a[x]>a[j])
                x=j;
            t=a[i];
            a[i]=a[x];
            a[x]=t;
    }
    for(i=0; i<10; i++)
        printf("%d\n",a[i]);
}
