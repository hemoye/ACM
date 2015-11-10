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
    int costtime;   //�Ѿ����ѵ�ʱ��
    int reduce;     //�۵��ķ���
    int pre;        //��һ��״̬
    int cur;        //����״̬�����һ����ҵ
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
            state[i].reduce = INF;              //��ǰ״̬�Ŀ۷�����Ϊ�����
            for ( int j = n; j >= 1; j-- ){     //ÿһ��j��ʾ��ǰ״̬���������ҵ
                int tmp = ( 1 << ( j - 1 ) );
                if ( i & tmp ){
                    int pre = i - tmp;          //����������preΪi��ǰ��״̬
                    int reduce = state[pre].reduce;//��ʾ��ǰ��״̬pre�����j֮��۵��ķ���
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
