#include <stdio.h>
#include <string.h>
#define MAX 55
int n, m, tmp;
int vis[MAX][MAX], mat[MAX][MAX];
void dfs(int x, int y)    //������
{
	if ( x < 0 || x >= n || y < 0 || y >= m )	return ;   //Խ�����
	if ( !vis[x][y] ){
		vis[x][y] = 1;
		tmp ++;
		if ( mat[x][y] < 8 ){  //˵��û����ǽ
			dfs(x+1, y);
		}
		else
            mat[x][y] %= 8;
		if ( mat[x][y] < 4 ){  //˵��û�ж�ǽ
			dfs(x, y+1);
		}
		else
            mat[x][y] %= 4;
		if ( mat[x][y] < 2 ){  //˵��û�б�ǽ
			dfs(x-1, y);
		}
		else
            mat[x][y] %= 2;
		if ( mat[x][y] < 1 ){  //˵��û����ǽ
			dfs(x, y-1);
		}
	}
}
int main(void)
{
	int i, j;
	scanf("%d %d", &n, &m);
	memset(vis, 0, sizeof(vis));
	for (i = 0; i < n; i ++){
		for (j = 0; j < m; j ++){
			scanf("%d", &mat[i][j]);
		}
	}
	int sum, max;
	sum = max = 0;
	for (i = 0; i < n; i ++){
		for (j = 0; j < m; j ++){
			if ( !vis[i][j] ){
				tmp = 0;   //��¼�߹��ķ���Ĳ���
				dfs(i, j);
				if ( tmp > max ){
					max = tmp;
				}
				if ( tmp ){  //�з����ۼ�
					sum ++;
				}
			}
		}
	}
	printf("%d\n%d\n", sum, max);
	return 0;
}
