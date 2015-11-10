#include <iostream>
#include <cstring>

int main( void )
{
    using namespace std;

    const int MAX = 4;
    char name[MAX];

    cout << "Please input your name:";
    cin  >> name;
    cout << name << ". Are you sure?" << endl;
    cout << "Your name have " << strlen( name ) << " bytes." << endl;
    cout << "But the array just have " << sizeof( name ) << " bytes.\n";

    return 0;
}
/**
    总结：
        与C语言的特性相似，C++的cin在就收字符串时
        不能接收到空格。且能够超出数组长度接收。
**/
