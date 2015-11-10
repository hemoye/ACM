#include <iostream>
#define  MAXSIZE 40

void print( char * );               //重载函数1
void print( char * , int );         //重载函数2

int main( void )
{
    using namespace std;

    int time;
    char str[MAXSIZE];

    cout << "请输入字符串:";
    cin >> str;

    cout << "您输入的字符串为：";
    print( str );

    cout << "请输入您要打印的次数:";
    cin >> time;
    print( str, time );

    return 0;
}
void print( char * ptr )
{
    using namespace std;

    cout << ptr << endl;

    return ;
}
void print( char * ptr, int n )
{
    using namespace std;

    for ( int i = 0; i < n; i++ )
        cout << ptr << endl;

    return ;
}
