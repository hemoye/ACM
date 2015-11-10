#include <iostream>

using namespace std;                        //名称空间定为全局变量，每一个函数都可以使用

void print1( void );                        //函数声明
void print2( void );                        //函数声明

int main( void )
{
    print1();                               //函数调用

    return 0;                               //返回语句
}
void print1( void )                         //函数原型
{
    print2();
    for ( int i = 0; i < 2; i++ )
        cout << "See how they run." << endl;
    return ;                                //返回语句
}
void print2()                               //函数原型
{
    for ( int i = 0; i < 2; i++ )
        cout << "Three blind mice." << endl;
    return ;                                //返回语句
}
