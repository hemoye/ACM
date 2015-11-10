#include <cstdio>

int main(int agrc, char *agrv[])
{
    int n;
    int a, b;

    scanf("%d", &n);
    while (n--){
        scanf("%d%d", &a, &b);
        printf("%d\n", a+b);
    }

    return 0;
}
