#include<stdio.h>
#include<string.h>
#define MAX 15
typedef struct node
{
    int x , y ;
    int s , c ;
} Q ;
Q q[MAX*MAX*3] ;
int vi[2][MAX][MAX] ;
char m[2][MAX][MAX] ;
int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}} ;
int N,M,T , find ,min ;
int ok(int i,int j)
{
    if(i>=0&&i<N&&j>=0&&j<M)
        return 1 ;
    return 0 ;
}
void remake()
{
    int i, j;
    for( i = 0 ; i < N ; i++)
        for( j = 0 ; j < M ; j++)
        {
            char a = m[0][i][j] , b = m[1][i][j] ;
            if(a=='#' && b=='#')
                a = b = '*' ;
            else if((a=='#' && b=='*')||(a=='*' && b=='#'))
                a = b = '*' ;
        }
}
void init()
{
    char *g ;
    int i, c, j;
    scanf("%d %d %d",&N,&M,&T) ;
    for( c = 0; c < 2 ; c++)
    {
        for( i = 0 ; i < N ; i++)
            scanf("%s",m[c][i]) ;
        if(!c) gets(g) ;
    }
}
void inq(int x , int y ,int head ,int tail ,int o)
{
    int c , s ;
    c = o?!(q[head].c) : q[head].c ;
    s = o? q[head].s : q[head].s+1 ;
    q[tail].x = x ;
    q[tail].y = y ;
    q[tail].c = c ;
    q[tail++].s = s ;
}
int bfs()
{
    int i, head=0 , tail=1 ,x , y ,c ;
    m[0][0][0] = '*' ;
    while(head < tail)
    {
        x = q[head].x , y = q[head].y ,c = q[head].c ;
        char tmp = m[c][x][y] ;
        if(tmp == 'P' && q[head].s <= T)
            return q[head].s ;
        if(tmp == '#')
        {
            if(!vi[!c][x][y])
                inq(x,y,head,tail,1) ;
            head++ ;
            vi[c][x][y] = 1 ;
            continue ;
        }
        for( i = 0 ; i < 4 ; i++)
        {
            int k = x+d[i][0] , v = y + d[i][1] ;
            if(ok(k,v) && !vi[c][k][v] && m[c][k][v] != '*')
                inq(k,v,head,tail,0) ;
        }
        vi[c][x][y] = 1 ;
        head++ ;
    }
    return 0 ;
}
int main()
{
    int ca ;
    scanf("%d",&ca) ;
    while(ca--)
    {
        memset(vi,0,sizeof(vi)) ;
        init() ;
        remake() ;
        if(bfs())printf("YES\n") ;
        else printf("NO\n") ;
    }
    return 0 ;
}
