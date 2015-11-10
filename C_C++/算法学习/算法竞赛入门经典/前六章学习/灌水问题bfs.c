#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100 + 10
#define min(a, b) (a) < (b) ? (a) : (b)
int cup[3], x;
typedef struct node
{
    int v[3], fa, last_op, dist;
} Node ;
Node q[MAXN];
int vis[MAXN][MAXN], front, rear;
void init (Node u)
{
    int i;
    for (i = 0; i < 3; i ++)	u.v[i] = 0;
    u.fa = u.last_op = u.dist = 0;
}
void print_path(int idx)
{
    if ( q[idx].fa != idx )
    {
        print_path(q[idx].fa);
        printf("cup %d -> cup %d\n", q[idx].last_op/10 + 1, q[idx].last_op%10 + 1);
    }
    printf("%d %d %d\n", q[idx].v[0], q[idx].v[1], q[idx].v[2]);
}
void bfs(void)
{
    front = rear = 0;
    init(q[0]);
    q[rear++].v[0] = cup[0];
    vis[0][0] = 1;
    while ( front < rear )
    {
        Node u;
        init(u);
        u = q[front];
        if ( u.v[0] == x || u.v[1] == x || u.v[2] == x )    //边界
        {
            printf("%d\n", u.dist);
            print_path(front);
            return ;
        }
        int i, j;
        for (i = 0; i < 3; i ++)
            for (j = 0; j < 3; j ++)
                if ( i != j )
                {
                    int amount = min(u.v[i], cup[j]-u.v[j]); //用小的减，大的会超过
                    Node v;
                    init(v);   //实现了宽度遍历
                    memcpy(&v, &u, sizeof(u));  //把结构u的数据用新的结点v去接收
                    v.v[i] -= amount;   //相当于枚举各种情况
                    v.v[j] += amount;
                    if ( !vis[v.v[1]][v.v[2]] )
                    {
                        vis[v.v[1]][v.v[2]] = 1;
                        v.fa = front;   //记录父亲结点为了遍历
                        v.dist = u.dist + 1;     //所走的的长度这里相当于倒了几次水
                        v.last_op = i * 10 + j;   //*10不是为了什么像迷宫还原原路径结点一样，*别的扡可以, 这里用来说明从
                        //哪个杯子到哪个杯子去
                        q[rear++] = v;
                    }
                }
        front ++;  //不能这在前面。因为是由front去找++后就变成别一个点了
    }
}
int main(void)
{
    scanf("%d %d %d %d", cup, cup+1, cup+2, &x);
    memset(vis, 0, sizeof(vis));
    bfs();
    return 0;
}
