#include <iostream>
#define  MAXN 40

int arrAy[MAXN];
int n, k;

using namespace std;
int  Seqarate( int , int );
bool Judge( int );

int main( void )
{
    int sum = 0, min = 0;

    while ( cin >> n )
    {
        for ( int i = 0; i < n; i++ )
        {
            cin >> arrAy[i];
            sum += arrAy[i];
            if ( min < arrAy[i] )
                min = arrAy[i];
        }
        cin >> k;

        int value = Seqarate( min, sum );
        cout << value << endl;
    }

    return 0;
}
int Seqarate( int low, int high )
{
    if ( low > high )
        return high + 1;
    int mid = ( low + high ) / 2;
    if ( Judge( mid ) )
        return Seqarate( low + 1, mid - 1 );
    else
        return Seqarate( mid + 1, high );
}
bool Judge( int mid )
{
    int seg = 0, sum = 0;

    for ( int i = 0; i < n; i++ )
    {
        sum += arrAy[i];
        if ( sum > mid )
        {
            sum = arrAy[i];
            seg++;
        }
    }
    if ( seg < k )
        return true;
    else
        return false;
}
