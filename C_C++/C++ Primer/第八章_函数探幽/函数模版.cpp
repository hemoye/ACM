#include <iostream>

template <class Any>
void Swap( Any &a, Any &b )
{
    Any temp = a;
    a = b;
    b = temp;

    return ;
}
int main( void )
{
    using namespace std;

    char m, n;

    cin >> n >> m;

    cout << "交换前:" << endl;
    cout << "n = " << n << ", m = " << m << endl;

    Swap( m, n );

    cout << "交换后:" << endl;
    cout << "n = " << n << ", m = " << m << endl;

    return 0;
}
