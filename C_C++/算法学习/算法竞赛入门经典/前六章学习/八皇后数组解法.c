#include <stdio.h>
#include <string.h>
#define MAX 100
int n, tot = 0;
int a[MAX], vis[MAX][MAX];
void search1(int pos)
{
    int i, j;
    if ( pos == n )	tot ++;
    else
    {
        for (i = 0; i < n; i ++)
        {
            /*
            	��������������ǰһ�������ǰ�ǰһ������Ҫ�жϵĶ���д�����������
            */
            if ( !vis[0][i] && !vis[1][pos+i] && !vis[2][pos-i+n] )
            {
                //���ö�ά����ֱ���ж�
                a[pos] = i;   //������ô�ӡ�⣬����a���鶼����ʡ��
                vis[0][i] = vis[1][pos+i] = vis[2][pos-i+n] = 1;  //�޸�ȫ�ֱ���
                //ע�⵽���Խ��߱�ʶy-x����Ϊ������ȡʱҪ����n
                search1(pos+1);
                vis[0][i] = vis[1][pos+i] = vis[2][pos-i+n] = 0;  //�Ļ���
            }
        }
    }
}
int main(void)
{
    scanf("%d", &n);
    memset(vis, 0, sizeof(vis));
    search1(0);
    printf("%d\n", tot);
    return 0;
}
