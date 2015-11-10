#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 15;
const int INF = 0x3fffffff;
const int MAX = 1 << N;

struct Work {
    char name[N*N];
    int deadline;
    int costtime;
} ;
struct State {
    int costtime;   //已经花费的时间
    int reduce;     //扣掉的分数
    int pre;        //上一个状态
    int cur;        //本次状态的最后一个作业
} ;
Work work[N+1];
State state[MAX];

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int n, T, D, C;
    scanf("%d", &T );
    while ( T-- ){
        scanf("%d", &n );
        for ( int i = 1; i <= n; i++ )  scanf("%s%d%d", work[i].name, &work[i].deadline, &work[i].costtime );
        int max_value = ( 1 << n );
        state[0].costtime = state[0].reduce = state[0].cur = 0;
        state[0].pre = -1;
        for ( int i = 1; i < max_value; i++ ){
            state[i].reduce = INF;              //当前状态的扣分设置为无穷大
            for ( int j = n; j >= 1; j-- ){     //每一个j表示当前状态最后做的作业
                int tmp = ( 1 << ( j - 1 ) );
                if ( i & tmp ){
                    int pre = i - tmp;          //这里计算出的pre为i的前导状态
                    int reduce = state[pre].reduce;//表示在前导状态pre下完成j之后扣掉的分数
                    if ( state[pre].costtime + work[j].costtime > work[j].deadline ){
                        reduce += state[pre].costtime + work[j].costtime - work[i].deadline;
                    }
                    if ( reduce < state[i].reduce ){
                        state[i].costtime = state[pre].costtime + work[j].costtime;
                        state[i].reduce = reduce;
                        state[i].pre = pre;
                        state[i].cur = j;
                    }
                }
            }
        }
        printf("%d\n", state[max_value-1].reduce );
        int cur = max_value - 1;
        int pos[n+1];
        int k = n;
        while ( state[cur].pre != -1 ){
            int now = state[cur].cur;
            pos[k--] = now;
            cur = state[cur].pre;
        }
        for ( int i = 1; i <= n; i++ )  printf("%s\n", work[pos[i]].name );
    }

    return 0;
}
