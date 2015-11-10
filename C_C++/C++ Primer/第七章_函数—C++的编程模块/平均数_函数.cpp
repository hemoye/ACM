#include <iostream>
#define  MAX 10

using namespace std;
int     Input( int * );
void    Output( int * , int );
double  Count( int * , int );

int main( void )
{
    int arrAy[MAX];
    int num, average;

    num = Input( arrAy );
    Output( arrAy, num );
    cout << Count( arrAy, num ) << endl;

    return 0;
}
int Input( int * p )
{
    int i = 0;

    while ( i < MAX && cin >> p[i++] );
    return i - 1;
}
void Output( int * p, int num )
{
    for ( int i = 0; i < num; i++ )
        cout << p[i] << endl;
    return ;
}
double Count( int * p, int num )
{
    double total = 0.0;

    for ( int i = 0; i < num; i++ )
        total += * ( p++ );
    return total / num;
}
