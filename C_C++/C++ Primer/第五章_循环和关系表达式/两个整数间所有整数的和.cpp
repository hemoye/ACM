#include <iostream>

int main( void )
{
    using namespace std;

    int m, n, total = 0;

    cout << "请输入两个整数:";
    cin  >> m >> n;                 //合法输入

    for ( int i = m; i <= n; i++ )
        total += i;

    cout << total << endl;

    return 0;
}
