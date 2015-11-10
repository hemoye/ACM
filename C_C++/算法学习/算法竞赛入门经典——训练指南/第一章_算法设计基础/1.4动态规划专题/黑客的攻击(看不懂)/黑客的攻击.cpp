#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define  INF 100000
using namespace std;

int p[20];
int cover[INF], f[INF];

int main( int agrc, char *agrv[] )
{
    int n;
    int kcase(0);
    while ( ~scanf("%d", &n ) && n ){
        for ( int i = 0; i < n; i++ ){
            int m, x;
            scanf("%d", &m );   //���봦��
            p[i] = 1 << i;
            while ( m-- ){
                scanf("%d", &x );   //��i���������ÿ���Ӽ���һ��Ԫ��
                p[i] |= 1 << x;     //��ÿ��Ԫ�ذ�λ��õ������γɵ�i���Ӽ����Ӽ���������ʾ��
            }
        }
        for ( int s = 0; s < ( 1 << n ); s++ ){//����1<<n���Ӽ�..���ڸ�����s����������p[i]�Ĳ���
            cover[s] = 0;
            for ( int i = 0; i < n; i++ ){//��s�������й�����Щ�����Ӽ�
                if ( s & ( 1 << i ) ){
                    cover[s] |= p[i];//���ڸ�����s����������p[i]�Ĳ���
                }
            }
        }
        f[0] = 0;
        int ALL = ( 1 << n ) - 1;//ȫ��
        for ( int s = 1; s < ( 1 << n ); s++ ){
            f[s] = 0;//f[s]��ʾ����s�����Էֳɶ�����
                    //��ôf[s] = max{f[s0]|s0��s���Ӽ�,cover[s0]Ϊȫ��}+1
            for ( int s0 = s; s0; s0 = ( s0 - 1 ) & s ){//ö��s���Ӽ�s0...ֻ�е���s0-1��&sʱs0-1����s���Ӽ�
                if ( cover[s0] == ALL ){ //�Ӽ���ȫ��һ���й���Ԫ��
                    f[s] = max( f[s], f[s^s0] + 1 );
                }
            }
        }
        printf("Case %d: %d\n", kcase++, f[ALL] );
    }

    return 0;
}
