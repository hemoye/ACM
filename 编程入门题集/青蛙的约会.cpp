#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int agrc, char *agrv[])
{
    int x, y, m, n, L;
    while (~scanf("%d%d%d%d%d", &x, &y, &m, &n, &L)){
        int xx = x, yy = y, count(0);
        do {
            xx = (xx + m) % L;              //��Ȧ��ѭ����
            yy = (yy + n) % L;
            count++;
            if (xx==yy) break;
        }while (xx!=x && yy!=y);            //����ֻ����ͬʱ�����Լ���ʼ��λ��ʱ������������Զ����������ͬһ����

        if (xx==x&&yy==y)   puts("Impossible");
        else    printf("%d\n", count);
    }

    return 0;
}
