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
        if ( u.v[0] == x || u.v[1] == x || u.v[2] == x )    //�߽�
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
                    int amount = min(u.v[i], cup[j]-u.v[j]); //��С�ļ�����Ļᳬ��
                    Node v;
                    init(v);   //ʵ���˿�ȱ���
                    memcpy(&v, &u, sizeof(u));  //�ѽṹu���������µĽ��vȥ����
                    v.v[i] -= amount;   //�൱��ö�ٸ������
                    v.v[j] += amount;
                    if ( !vis[v.v[1]][v.v[2]] )
                    {
                        vis[v.v[1]][v.v[2]] = 1;
                        v.fa = front;   //��¼���׽��Ϊ�˱���
                        v.dist = u.dist + 1;     //���ߵĵĳ��������൱�ڵ��˼���ˮ
                        v.last_op = i * 10 + j;   //*10����Ϊ��ʲô���Թ���ԭԭ·�����һ����*��ĒL����, ��������˵����
                        //�ĸ����ӵ��ĸ�����ȥ
                        q[rear++] = v;
                    }
                }
        front ++;  //��������ǰ�档��Ϊ����frontȥ��++��ͱ�ɱ�һ������
    }
}
int main(void)
{
    scanf("%d %d %d %d", cup, cup+1, cup+2, &x);
    memset(vis, 0, sizeof(vis));
    bfs();
    return 0;
}
