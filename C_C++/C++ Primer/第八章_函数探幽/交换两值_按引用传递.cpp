#include <iostream>

using namespace std;
void swap( int &, int & );

int main( void )
{
    int first = 4, last = 8;

    swap( first, last );

    cout << &first << " " << &last << endl;
    cout << first << " " << last << endl;
    cout << &first << " " << &last << endl;

    return 0;
}
void swap( int & a, int & b )
{
    int temp = a;
    a = b;
    b = temp;

    return ;
}
/**
    ��codebloks������Ľ���ǣ�
            0x22ff0c 0x22ff08
            8 4
            0x22ff0c 0x22ff08
    �ܽ�:
        �������Ͻ����ʾ��
        �����ô��ݽ�������ֵ�����ύ����ַ
**/
