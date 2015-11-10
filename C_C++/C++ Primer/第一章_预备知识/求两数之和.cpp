#include <iostream>

int main( void )
{
    using namespace std;        //名称空间(不知何用，但必须使用才能运行程序，否则报错不能运行)

    int a, b;                   //声明语句(分配足够的存储空间来存储两个整数，并用a，b来标识储存在该内存单元中的值)
    a = b = 1;                  //赋值语句(在这两个内存单元中存入两个值)

    cout << a + b << endl;      //输出

    return 0;
}
