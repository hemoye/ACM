#include <cstdio>

int main(int agrc, char *agrv[])
{
    /**
          1��n�η�����λ����Ϊ��1 1 1 1   1 1 1 1 ...
          2��n�η�����λ����Ϊ��2 4 8 6   2 4 8 6 ...
          3��n�η�����λ����Ϊ��3 9 7 1   3 9 7 1 ...
              .....
          0��9 ÿһ������n�η�����ĸ�λ�����ǰ�4ѭ����.
    **/
    int n, N;

    scanf("%d", &N);

    while (N--){
        scanf("%d", &n);
        if (0 == n % 10)    puts("0");
        else {
            int m = n % 4 + 4;
            int ans(1);
            for (int i = 0; i < m; i++) ans = (ans * (n % 10)) % 10;
            printf("%d\n", ans);
        }
    }

    return 0;
}
