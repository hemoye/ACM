#include <iostream>

int main( void )
{
    using namespace std;

    int temp, count = 0;

    cout << "请输入一个数字(以0为结束):";
    cin  >> temp;
    while ( temp != 0 )
    {
        count++;
        cout << "请输入一个数字(以0为结束):";
        cin  >> temp;
    }
    cout << count << endl;

    return 0;
}
