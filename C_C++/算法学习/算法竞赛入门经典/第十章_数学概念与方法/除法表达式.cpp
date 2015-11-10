/**问题描述:
        给出一个这样的除法表达式:X1/X2/X3.../Xn,其中Xi是正整数。除法表达式
        应当按照从左到右的顺序求和，例如表达式1/2/1/2的值为1/4。但可以在表
        达式中嵌入括号以改便计算顺序，如表达式(1/2)/(1/2)的值为1。

        输入X1,X2,X3……Xn,判断是否可以通过添加括号，是表达式的值为整数.
**/

#include <iostream>
#define  MAXN 40

using namespace std;

int  n;
bool Judge( int * );
int  Gcd( int , int );

int main( void )
{
    int arrAy[MAXN];

    cin >> n;
    for ( int i = 0; i < n; i++ ){
        cin >> arrAy[i];
    }
    if ( Judge( arrAy ) ){
        cout << "Yes." << endl;
    }
    else {
        cout << "No." << endl;
    }

    return 0;
}
bool Judge( int * arrAy )
{
    arrAy[1] /= Gcd( arrAy[1], arrAy[0] );
    for ( int i = 2; i < n; i++ ){
        arrAy[1] /= Gcd( arrAy[i], arrAy[1] );
        if ( arrAy[1] == 1 ){
            return true;
        }
    }
    return false;
}
int Gcd( int m, int n )                         /**递归求解最大公约数**/
{
    return n == 0 ? m : Gcd( n, m % n );
}
