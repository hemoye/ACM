#include <cstdio>

int main(int agrc, char *agrv[])
{
    /**
          1的n次方，各位依次为：1 1 1 1   1 1 1 1 ...
          2的n次方，各位依次为：2 4 8 6   2 4 8 6 ...
          3的n次方，各位依次为：3 9 7 1   3 9 7 1 ...
              .....
          0到9 每一个数的n次方结果的个位数都是按4循环的.
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
