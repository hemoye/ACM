#include <iostream>
#include <cstring>
#define  MAXN 40

int n;
int arrAy[MAXN];

int Feibola( int );

int main( void )
{
    using namespace std;

    while ( cin >> n ){
        memset( arrAy, -1, sizeof( arrAy ) );
        arrAy[0] = 1;
        arrAy[1] = 2;
        cout << Feibola( n - 1 ) << endl;
    }

    return 0;
}
int Feibola( int x )
{
    if ( x == 0 )   return arrAy[x];
    else if ( 1 == x )  return arrAy[x];
    if ( -1 == arrAy[x] )   return Feibola( x - 1 ) + Feibola( x - 2 );
    else    return arrAy[x];
}
