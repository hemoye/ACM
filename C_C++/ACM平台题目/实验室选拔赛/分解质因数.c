#include <stdio.h>
int main(void)
{
    int n, i, j, a[1001]= {0}, m;
    scanf("%d", &n);
    for(i=2; i<=n; i++)
    {
        m = i;
        j=2;
        while(m!=1)
        {
            if(m%j==0)
            {
                a[j]++;
                j=2;
                m/=j;
            }
            else
                j++;
        }
    }
    for(i=2; i<=n; i++)
    {
        if(a[i]==1)
            printf("%d*", i);
        else if(a[i]>1)
            printf("%d^%d*", i, a[i]);
    }
    return 0;
}
