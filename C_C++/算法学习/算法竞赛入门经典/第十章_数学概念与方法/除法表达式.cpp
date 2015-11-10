/**��������:
        ����һ�������ĳ������ʽ:X1/X2/X3.../Xn,����Xi�����������������ʽ
        Ӧ�����մ����ҵ�˳����ͣ�������ʽ1/2/1/2��ֵΪ1/4���������ڱ�
        ��ʽ��Ƕ�������Ըı����˳������ʽ(1/2)/(1/2)��ֵΪ1��

        ����X1,X2,X3����Xn,�ж��Ƿ����ͨ��������ţ��Ǳ��ʽ��ֵΪ����.
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
int Gcd( int m, int n )                         /**�ݹ�������Լ��**/
{
    return n == 0 ? m : Gcd( n, m % n );
}
