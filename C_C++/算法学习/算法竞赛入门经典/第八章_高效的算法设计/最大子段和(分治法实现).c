#include <stdio.h>
#define  MAXN 40

int Max_Sum( int , int , int * );

int main( void )
{
    int i, n;
    int arrAy[MAXN];

    freopen( "test.txt", "r", stdin );

    scanf("%d", &n );
    for ( i = 0; i < n; i++ )
        scanf("%d", &arrAy[i] );

    int max = Max_Sum( 0, n, arrAy );
    printf("%d\n", max );

    return 0;
}
int Max_Sum( int m, int n, int * ptr )
{
    if ( 1 == n - m )
        return ptr[m];

    int i, v, max, left, right;
    int half = m + ( n - m ) / 2;
    int L = Max_Sum( m, half, ptr );
    int R = Max_Sum( half, n, ptr );

    max = L > R ? L : R;

    v = 0;
    left = ptr[m];
    for ( i = half - 1; i >= 0; i-- )
    {
        v += ptr[i];
        if ( left < v )
            left = v;
    }

    v = 0;
    right = ptr[half];
    for ( i = half; i < n; i++ )
    {
        v += ptr[i];
        if ( right < v )
            right = v;
    }

    return max > ( left + right ) ? max : left + right;
}
//#include<stdio.h>
//int a[11];
//int main()
//{
//    int maxsubsum(int left,int right);
//    int i;
//    int sum;
//    a[0]=0;
//    freopen( "test.txt", "r", stdin );
//    for(i=1; i<11; i++)
//        scanf("%d",&a[i]);
//    sum=maxsubsum(1,10);
//    printf("%d\n",sum);
//}
//int maxsubsum(int left,int right)
//{
//    int sum=0,i;
//    int leftsum=0,rightsum=0,lefts=0,rights=0,s1=0,s2=0;
//    if(left==right)
//        sum=a[left]>0?a[left]:0;
//    else
//    {
//        int mid=(left+right)/2;
//        leftsum=maxsubsum(left,mid);
//        rightsum=maxsubsum(mid+1,right);
//        for(i=mid; i>=0; i--)
//        {
//            lefts+=a[i];
//            if(lefts>s1)
//                s1=lefts;
//        }
//        for(i=mid+1; i<=right; i++)
//        {
//            rights+=a[i];
//            if(rights>s2)
//                s2=rights;
//        }
//    }
//    sum=s1+s2;
//    if(sum<leftsum)
//        sum=leftsum;
//    if(sum<rightsum)
//        sum=rightsum;
//    return sum;
//}
