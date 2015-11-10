/**
���������е��ƹ�ϵ��
    ��һ�֡�H(n) = H(0)*H(n-1)+H(1)*H(n-2)+H(2)*H(n-3)+...+H(n-1)*H(0)
    �ڶ��֡�H(n) = C(2n, n)/(n+1)
    �����֡�H(n) = C(2n, n) - C(2n, n + 1 )
���������ƹ�ϵ����һ�ֽⷨ:
    H(n) = ( 4n - 6 ) / n * H( n - 1 )  (��ʱ�ı߽����Ϊ: H(2) = H(3) = 1 )
    eg:�ɽ����λ��������εĸ���.
**/

#include <iostream>
#define  MAXN 40

using namespace std;

int main( void )
{
    int n;
    int arrAy[MAXN];

    while ( true ){
        cout << "Please enter the number of the sides of the polygon:";
        cin >> n;
        if ( n < 3 ){
            break;
        }
        arrAy[2] = arrAy[3] = 1;
        for ( int i = 3; i < n; i++ ){
            arrAy[i+1] = ( 4 * i - 6 ) * arrAy[i] / i ;
        }
        cout << "The polygan can be divided into " << arrAy[n] << " traingles." << endl;
    }

    return 0;
}
