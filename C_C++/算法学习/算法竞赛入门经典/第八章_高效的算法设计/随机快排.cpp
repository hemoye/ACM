#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXN 100
#define SWAP(x , y , tmp) tmp = x , x = y , y = tmp
int A[MAXN] ;

void QuickSort(int , int ) ;

int main(void)
{
    int n , i ;
    scanf("%d" , &n) ;
    for (i = 0 ; i < n ; ++ i)
    {
        scanf("%d" , &A[i]) ;
    }
    QuickSort(0 , n-1) ;
    for (i = 0 ; i < n ; ++ i)
    {
        printf(i ?" %d":"%d" , A[i]) ;
    }
    return 0 ;
}

int Findpos(int low , int high)
{
    int i = low + rand() % (high - low) ;
    int tmp ;
    SWAP(A[i] , A[low] , tmp) ;
    int val = A[low] ;
    while ( low < high )
    {
        while ( low < high && A[high] >= val )
        {
            -- high ;
        }
        A[low] = A[high] ;
        while ( low < high && A[low] <= val )
        {
            ++ low ;
        }
        A[high] = A[low] ;
    }
    A[low] = val ;
    return low ;
}

void QuickSort(int low , int high)
{
    int pos ;
    if ( low < high )
    {
        pos = Findpos(low , high) ;
        QuickSort(low , pos-1) ;
        QuickSort(pos+1 , high) ;
    }
}
