#include <iostream>
#include <cstring>
#define  MAXN 400

using namespace std;

int main( void )
{
    int n;
    int arrAy[MAXN];

    while ( cin >> n ){
        int temp = n;
        memset( arrAy, 0, sizeof( arrAy ) );
        for ( int i = 2; n > 1; i++ ){
            if ( 0 == n % i ){
                arrAy[i]++;                     //���ÿһ���������ӵĸ���
                n /= i;
                i = 1;
            }
        }
        int sum( 1 );
        for ( int i = 0; i < temp; i++ ){
            sum *= ( arrAy[i] + 1 );            //���ù�ʽ�۳˼������е���Լ������
        }
        cout << sum << endl;
    }

    return 0;
}
