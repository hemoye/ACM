#include <iostream>
#define  MAXSIZE 40

void print( char * );               //���غ���1
void print( char * , int );         //���غ���2

int main( void )
{
    using namespace std;

    int time;
    char str[MAXSIZE];

    cout << "�������ַ���:";
    cin >> str;

    cout << "��������ַ���Ϊ��";
    print( str );

    cout << "��������Ҫ��ӡ�Ĵ���:";
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
