#include <iostream>

using namespace std;                        //���ƿռ䶨Ϊȫ�ֱ�����ÿһ������������ʹ��

void print1( void );                        //��������
void print2( void );                        //��������

int main( void )
{
    print1();                               //��������

    return 0;                               //�������
}
void print1( void )                         //����ԭ��
{
    print2();
    for ( int i = 0; i < 2; i++ )
        cout << "See how they run." << endl;
    return ;                                //�������
}
void print2()                               //����ԭ��
{
    for ( int i = 0; i < 2; i++ )
        cout << "Three blind mice." << endl;
    return ;                                //�������
}
