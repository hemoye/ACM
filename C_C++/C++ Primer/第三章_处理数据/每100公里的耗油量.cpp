#include <iostream>

int main( void )
{
    using namespace std;
    float distance, bulk;

    cout << "��������ʻ����·��:_____\b\b\b\b\b";
    cin  >> distance;
    cout << "�����������:_____\b\b\b\b\b";
    cin  >> bulk;

    cout << bulk * 100 / distance << endl;

    return 0;
}
