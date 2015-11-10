#include <iostream>

int main( void )
{
    using namespace std;

    const int MAX = 5;
    double arrAy[MAX];

    for ( int i = 0; i < MAX; i++ )
    {
        while ( !( cin >> arrAy[i] ) ){
            cin.clear();
            while ( cin.get() != '\n' )
                continue;
            cout << "请重新输入一个数字:";
        }
    }
    for ( int i = 0; i < MAX; i++ )
        cout << arrAy[i] << endl;

    return 0;
}
