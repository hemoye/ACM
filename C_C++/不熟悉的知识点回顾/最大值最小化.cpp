#include <iostream>
#define  MAXN 40

int n, k;
int arrAy[MAXN];

int Sqarate( int , int );
bool Judge( int );

int main( void )
{
    using std::cout;
    using std::endl;
    using std::cin;

    int sum = 0, min = MAXN;

    while ( cin >> n )
    {
        for ( int i = 0;i < n; i++ )
        {
            cin >> arrAy[i];
            sum += arrAy[i];
            if ( min > arrAy[i] )
                min = arrAy[i];
        }
        cin >> k;

        int value = Sqarate( min, sum );
        cout << value << endl;
    }

    return 0;
}
int Sqarate( int low, int high )
{
    if ( low > high )
        return high + 1;
    int mid = ( low + high ) / 2;

    if ( Judge( mid ) )
        return Sqarate( low, mid - 1 );
    else
        return Sqarate( mid + 1, high );
}
bool Judge( int mid )
{
    int sum = 0, sge = 0;

    for ( int i = 0; i < n; i++ )
    {
        sum += arrAy[i];
        if ( sum > mid )
        {
            sum = arrAy[i];
            sge++;
        }
    }
    if ( sge < k )
        return true;
    else
        return false;
}
