#include <iostream>
#include <string>

int main( void )
{
    using namespace std;
    string str1, str2;

    cin  >> str1;
    cout << str1 << endl;
    str2 = str1;
    cout << str2 << endl;
    str1 += str2;
    cout << str1 << endl;
    str1 += "shacha";
    cout << str1 << endl;
    cout << str1.size() << endl;

    return 0;
}
