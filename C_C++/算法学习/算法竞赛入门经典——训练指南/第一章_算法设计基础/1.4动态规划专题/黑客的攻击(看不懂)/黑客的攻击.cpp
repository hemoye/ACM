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
            scanf("%d", &m );   //输入处理
            p[i] = 1 << i;
            while ( m-- ){
                scanf("%d", &x );   //第i个计算机是每个子集的一个元素
                p[i] |= 1 << x;     //将每个元素按位或得到并集形成第i个子集（子集用整数表示）
            }
        }
        for ( int s = 0; s < ( 1 << n ); s++ ){//共有1<<n个子集..对于给定的s集合中所有p[i]的并集
            cover[s] = 0;
            for ( int i = 0; i < n; i++ ){//第s个集合中共有哪些上述子集
                if ( s & ( 1 << i ) ){
                    cover[s] |= p[i];//对于给定的s集合中所有p[i]的并集
                }
            }
        }
        f[0] = 0;
        int ALL = ( 1 << n ) - 1;//全集
        for ( int s = 1; s < ( 1 << n ); s++ ){
            f[s] = 0;//f[s]表示集合s最多可以分成多少组
                    //那么f[s] = max{f[s0]|s0是s的子集,cover[s0]为全集}+1
            for ( int s0 = s; s0; s0 = ( s0 - 1 ) & s ){//枚举s的子集s0...只有当（s0-1）&s时s0-1才是s的子集
                if ( cover[s0] == ALL ){ //子集与全集一定有公共元素
                    f[s] = max( f[s], f[s^s0] + 1 );
                }
            }
        }
        printf("Case %d: %d\n", kcase++, f[ALL] );
    }

    return 0;
}
