/**����������
        �ռ�����n����Po,P1����Pn-1;��������ǰ��������n/2�ԣ�nΪż����,
        ʹ��ÿ����ǡ����һ������С����е��������ľ���֮��Ӧ����С.
**/
#include <iostream>
#include <cstring>
#define  MAXN 40

using namespace std;

int arrAy[MAXN], dis[MAXN];
int dp( int );

int main( void )
{
    int n;
    cin >> n;
    for ( int i = 0; i < n; i++ ){
        cin >> arrAy[i];
    }
    dp( n );
    int Min( 0 );
    for ( int i = 0; i < n / 2; i++ ){
        Min += dis[i];
    }
    cout << Min << endl;

    return 0;
}
int dp( int n )
{
    if ( n <= 0 ){
        return 0;
    }
}
