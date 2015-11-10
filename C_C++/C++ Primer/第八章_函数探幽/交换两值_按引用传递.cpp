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
    在codebloks中输出的结果是：
            0x22ff0c 0x22ff08
            8 4
            0x22ff0c 0x22ff08
    总结:
        根据以上结果显示：
        按引用传递交换两个值并不会交换地址
**/
