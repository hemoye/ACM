#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,k,j,m,a[100][100];
    scanf("%d",&n);
    m=1;
    for(i=0; i<n; i++)
        for(k=0,j=i; j>=0; j--)
        {
            a[j][k]=m;
            m++;
            k++;
        }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i; j++)
            printf(" %d",a[i][j]);
        printf("\n");
    }
}
