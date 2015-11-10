#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
#define CNT     3
#define MAXN    10 + 10
#define INF     0x3f3f3f3f
#define REPD(i, e, s)   for(int i = (e); i >= (s); i --)
#define REPI(i, s, e)   for(int i = (s); i <= (e); i ++)
 
int matrix[MAXN][MAXN], x, y;
 
void change(char ch)
{
        if( 'U' == ch ) {
                if( 1 == x ) {
                        return;
                }
                swap(matrix[x][y], matrix[x-1][y]);
                x -= 1;
        }
        else if( 'D' == ch ) {
                if( CNT == x ) {
                        return;
                }
                swap(matrix[x][y], matrix[x+1][y]);
                x += 1;
        }
        else if( 'L' == ch ) {
                if( 1 == y ) {
                        return;
                }
                swap(matrix[x][y], matrix[x][y-1]);
                y -= 1;
        }
        else if( 'R' == ch ) {
                if( CNT == y ) {
                        return;
                }
                swap(matrix[x][y], matrix[x][y+1]);
                y += 1;
        }
}
 
int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
        freopen("test.in", "r", stdin);
#endif
        int cas;
        scanf("%d", &cas);
        REPI(k, 1, cas) {
                REPI(i, 1, CNT) {
                        REPI(j, 1, CNT) {
                                scanf("%d", &matrix[i][j]);
                                if( !matrix[i][j] ) {
                                        x = i, y = j;
                                }
                        }
                }
                int m;
                char ch[3];
                scanf("%d", &m);
                REPI(i, 1, m) {
                        scanf("%s", ch);
                        change(*ch);
                }
                REPI(i, 1, CNT) {
                        REPI(j, 1, CNT-1) {
                                printf("%d ", matrix[i][j]);
                        }
                        printf("%d\n", matrix[i][CNT]);
                }
                printf("\n");
        }
        return 0;
}
/**************************************************************
	Problem: 5496
	User: Pascal
	Language: Java
	Result: Accepted
	Time:12 ms
	Memory:16044 kb
****************************************************************/
