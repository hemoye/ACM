#include<stdio.h>
main()
{
    int k,a[100],n,i,j,sum,t,c=1,max;
    scanf("%d",&sum);
    for(i=0; i<sum; i++)
    {
        scanf("%d",&n);
        for(j=0; j<n; j++)
        {
            scanf("%d",&a[j]);
        }
        for(j=0; j<n-1; j++)
        {
            max=j;
            for(k=j+1; k<n; k++)
            {
                if(fabs(a[max])<fabs(a[k]))
                {
                    max=k;
                    t=a[j];
                    a[j]=a[max];
                    a[max]=t;
                }
            }
        }
        printf("Case %d: ",c);
        c++;
        for(j=0; j<n; j++)
        {
            printf((j==0)?"%d":" %d",a[j]);
        }
        printf("\n");
    }
}
