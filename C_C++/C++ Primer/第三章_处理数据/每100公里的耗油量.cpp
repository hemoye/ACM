#include <iostream>

int main( void )
{
    using namespace std;
    float distance, bulk;

    cout << "请输入行驶的总路程:_____\b\b\b\b\b";
    cin  >> distance;
    cout << "请输入耗油量:_____\b\b\b\b\b";
    cin  >> bulk;

    cout << bulk * 100 / distance << endl;

    return 0;
}
