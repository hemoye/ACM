#include <iostream>
#define  Swap( a, b, t ) t = a, a = b, b = t

int GCD( int m, int n );                    //����ԭ��

int main( void )
{
    using std::cout;
    using std::endl;
    using std::cin;

    int m, n;

    while ( cin >> m >> n )
        cout << GCD( m, n ) << endl;

    return 0;
}
int GCD( int m, int n )                     //���庯��
{
    int temp = m;

    if ( m < n )
        Swap( m, n, temp );
    while ( temp )
    {
        temp = m % n;
        m = n;
        n = temp;
    }

    return m;
}
