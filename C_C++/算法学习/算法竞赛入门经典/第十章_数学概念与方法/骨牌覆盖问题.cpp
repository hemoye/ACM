#include <iostream>
#define  MAXN 400

using namespace std;

int Fibonacci[MAXN];
void InitFibonacci( void );

int main( void )
{
    int n;
    InitFibonacci();
    while ( cin >> n ){
        int sum( 0 );
        if ( n % 2 ){
            for ( int i = n - 1; i >= 0; i -= 2 ){
                sum += Fibonacci[i];
            }
        }
        else {
            sum = 1;
            for ( int i = n - 1; i > 0; i -= 2 ){
                sum += Fibonacci[i];
            }
        }
        cout << sum << endl;
    }
    return 0;
}
void InitFibonacci( void )
{
    Fibonacci[0] = Fibonacci[1] = 1;
    for ( int i = 2; i < MAXN; i++ ){
        Fibonacci[i] = Fibonacci[i-1] + Fibonacci[i-2];
    }
    return ;
}
/**
    总结：即斐波拉契数列（Fibonacci）
    1、一个数列可囊有多个看上去完全不同的递推关系
    2、即使是个漏洞百出的解法也有可能通过"打补丁“的方式修改正确
**/
