/**问题描述：
        对于给定的n个数a1, a2...an;依次求出相邻两数之和，将得到一个新数列。
        重复上述操作，最后结果变成一个数。问这个数除以m的余数与哪些数无关
    解题思路：
        可以看成一个n次二项式的展开式，看第几项的系数是m的倍数
**/
#include <iostream>
#define  MAXN 40

using namespace std;

int main( void )
{
    int m, n;
    int arrAy[MAXN];
    int Quad[MAXN];

    while ( cin >> n >> m ){
        for ( int i = 0; i < n; i++ ){
            cin >> arrAy[i];
        }
        Quad[0] = 1;
        for ( int i = 1; i < n; i++ ){
            Quad[i] = Quad[i-1] * ( n - i ) / i;
        }
        for ( int i = 0; i < n; i++ ){
            cout << Quad[i] << " ";
        }
        cout << endl;
        for ( int i = 0; i < n; i++ ){
            if ( 0 == Quad[i] % m ){
                cout << "与第" << i + 1 << "项" << arrAy[i] << "的值无关" << endl;
            }
        }
    }

    return 0;
}
