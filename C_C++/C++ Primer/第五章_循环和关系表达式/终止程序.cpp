#include <iostream>

int main( void )
{
    using namespace std;

    int temp, count = 0;

    cout << "������һ������(��0Ϊ����):";
    cin  >> temp;
    while ( temp != 0 )
    {
        count++;
        cout << "������һ������(��0Ϊ����):";
        cin  >> temp;
    }
    cout << count << endl;

    return 0;
}
