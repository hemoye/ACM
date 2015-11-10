#include <stdio.h>
#include <mem.h>
#include <time.h>
#include <math.h>
#define N 362880+10

typedef struct sta
{
    int a[9];
} state;

int fact[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int vis[N];
int dis[N];
state Q[N];

const int d[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

int compu_fact(void);  //编码
int code(state s);   //解码
int rev_num(state s);
int bfs(state start, state goal);
int manh_dis(state s1, state s2);

int main(void)
{
    int i, j;
    state start, goal;
//
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//
    //compu_fact();  构造fact
    for (i = 0; i < 9; i ++)	scanf("%d", &start.a[i]);
    for (i = 0; i < 9; i ++)	scanf("%d", &goal.a[i]);
    /*
       if ((rev_num(start)+manh_dis(start, goal))%2 != rev_num(goal)%2) printf("-1\n");
       这里的剪枝不太理解，总是把可解的状态也剪掉了
    */
    printf("%d\n", bfs(start, goal));
    printf("time used %.3lfs.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}

int bfs(state start, state goal)
{
    int front, rear;
    int nx, ny, x, y, z, nz;
    int code_t, code_nt;
    memset(vis, 0, sizeof(vis));

    front = 0;
    rear = 1;
    Q[front] = start;
    dis[(code(start))] = 0;

    while (front < rear)
    {
        state t = Q[front++];
        code_t = code(t);
        if ( memcmp(&t, &goal, sizeof(goal)) == 0 ) return dis[code_t];
        for (z = 0; t.a[z] != 0 && z < 9; ++ z) ;
        x = z / 3;
        y = z % 3;
        int i;
        for (i = 0; i < 4; ++ i)
        {
            nx = x + d[i][0];
            ny = y + d[i][1];
            nz = 3*nx + ny;
            if (nx>=0 && nx<3 && ny>=0 && ny<3)
            {
                state nt = t;
                nt.a[z] = t.a[nz];
                nt.a[nz] = 0;
                code_nt = code(nt);
                if (!vis[code_nt])
                {
                    vis[code_nt] = 1;
                    Q[rear++] = nt;
                    dis[code_nt] = dis[code_t] + 1;
                }
            }
        }
    }
    return -1;
}

int code(state s)
{
    int i, j, cnt, ret;
    ret = 0;
    for (i = 0; i < 9; ++ i)
    {
        cnt = 0;
        for (j = i+1; j < 9; ++ j)
            if (s.a[j] < s.a[i]) ++cnt;
        ret += fact[8-i]*cnt;
    }
    return ret;
}

int compu_fact(void)
{
    int i;

    fact[0] = 1;
    for (i = 1; i < 9; ++i)
        fact[i] = fact[i-1]*i;
}

int rev_num(state s)
{
    int i, j, ret;

    ret = 0;
    for (i = 0; i < 9; ++i)
        for (j = i+1; j < 9; ++j)
            if (s.a[i] > s.a[j]) ++ret;

    return ret;
}

int manh_dis(state s1, state s2)
{
    int i, j;

    for (i = 0; s1.a[i]!=0 && i<9; ++i) ;
    for (j = 0; s2.a[j]!=0 && j<9; ++j) ;

    return abs(i/3 - j/3) + abs(i%3 - j%3);
}
