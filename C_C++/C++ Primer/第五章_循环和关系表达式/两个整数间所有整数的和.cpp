#include <iostream>

int main( void )
{
    using namespace std;

    int m, n, total = 0;

    cout << "��������������:";
    cin  >> m >> n;                 //�Ϸ�����

    for ( int i = m; i <= n; i++ )
        total += i;

    cout << total << endl;

    return 0;
}
