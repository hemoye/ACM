#include <iostream>
#include <ctime>
#define  MAXN 40

int arrAy[MAXN];
void Quick_Sort( int , int );
int  Find_Pos( int , int );

int main( void )
{
    using std::cout;
    using std::endl;

    int i, n;
    time_t start;

    while ( std::cin >> n )
    {
        if ( 0 == n )
            break;
        for ( i = 0; i < n; i++ )
            std::cin >> arrAy[i];

        start = clock();

        Quick_Sort( 0, n - 1 );
        for ( i = 0; i < n; i++ )
            cout << arrAy[i] << " ";
        cout << endl;
        cout << ( double )( clock() - start ) / CLOCKS_PER_SEC << "s" << endl;
    }

    return 0;
}
void Quick_Sort( int low, int high )
{
    int pos;

    if ( low < high )
    {
        pos = Find_Pos( low, high );
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
