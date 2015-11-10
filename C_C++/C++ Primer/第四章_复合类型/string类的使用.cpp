#include <iostream>
#include <string>

int main( void )
{
    using namespace std;
    const int MAX = 24;
    char name[MAX];
    char data[MAX];
    string str1;
    string str2 = "xiemei";

    cin  >> name;
    cin  >> data;
    cout << name << " and " << data << "?\n";
    //cin  >> str1;
    cin.get();
    getline( cin, str1 );           //这样就可以吃回车
    cout << str1 << endl;
    cout << str2[2] << endl;

    return 0;
}
