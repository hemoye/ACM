/**
    问题描述：在黑板上写了N个正整数作成的一个数列，进行如下操作:每一次擦去其中的两个数a和b，
然后在数列中加入一个数a×b+1，如此下去直至黑板上剩下一个数，在所有按这种操作方式最后得到的数
中，最大的max，最小的为min，则该数列的极差定义为M=max-min。
    编程任务：对于给定的数列，编程计算出极差M。
**/

#include <iostream>
#define  MAXN 40

void Quick_Sort( int , int );
int  Find_Pos( int , int );

int arrAy[MAXN];

int main( void )
{
    using namespace std;
    int n;

    cin >> n;
    for ( int i = 0; i < n; i++ )
        cin >> arrAy[i];
    Quick_Sort( 0, n - 1 );

    int max = arrAy[0];
    for ( int i = 1; i < n; i++ )
        max = max * arrAy[i] + 1;

    int min = arrAy[n-1];
    for ( int i = n - 2; i >= 0; i-- )
        min = min * arrAy[i] + 1;
    cout << max << " " << min << endl;
    cout << max - min << endl;

    return 0;
}
void Quick_Sort( int low, int high )
{
    if ( low < high )
    {
        int pos = Find_Pos( low, high );
        Quick_Sort( low, pos - 1 );
        Quick_Sort( pos + 1, high );
    }
    return ;
}
int Find_Pos( int low, int high )
{
    int val = arrAy[low];

    while ( low < high )
    {
        while ( low < high && arrAy[high] >= val )
            high--;
        arrAy[low] = arrAy[high];
        while ( low < high && arrAy[low] <= val )
            low++;
        arrAy[high] = arrAy[low];
    }
    arrAy[low] = val;

    return low;
}
