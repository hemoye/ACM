#include <iostream>
#include <cstring>

int main( void )
{
    using namespace std;

    const int SIZE = 24;

    char name[SIZE];

    cout << "Now, Please input your name: ";
    cin  >> name;
    cout << "The array have " << sizeof( name ) << " letters." << endl;
    cout << "Ok, " << name << "! Your name have " << strlen( name ) << " bytes.\n";

    return 0;
}
/**
样例输入：
        hemoxie
样例输出：
        Now, Please input your name: hemoxie
        The array have 24 letters.
        Ok, hemoxie! Your name have 7 bytes.
**/
/****
总结：
     strlen计算的是数组的实际长度
     sizeof计算的是数组已被分配的
     内存的总长度
****/
