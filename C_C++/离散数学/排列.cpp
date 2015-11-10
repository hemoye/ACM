#include <iostream>
#define  MAX 10
#define  Swap( a, b, t ) t = a, a = b, b = t

char arrAy[MAX];

void Rank( int , int );                     //交换函数

int main( void )
{
    using std::cout;
    using std::endl;

    std::cin >> arrAy;                      //输入字符串

    Rank( 0, 2 );

    return 0;
}
void Rank( int first, int  last )
{
    using std::cout;
    using std::endl;

    char temp;

    if ( first == last )
        cout << arrAy << endl;             //输出
    else
    {
        for ( int i = first; i < 3; i++ )   //格式化选座位
        {
            Swap( arrAy[first], arrAy[i], temp );
            Rank( first + 1, last );
            Swap( arrAy[first], arrAy[i], temp );
        }
    }

    return ;
}
