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

    cout << "����ǰ:" << endl;
    cout << "n = " << n << ", m = " << m << endl;

    Swap( m, n );

    cout << "������:" << endl;
    cout << "n = " << n << ", m = " << m << endl;

    return 0;
}
