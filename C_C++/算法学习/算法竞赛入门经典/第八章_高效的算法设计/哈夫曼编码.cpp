#include <cstdio>
int main(void)
{
    int a[] = {-1, 2, 3, -4, 5, -3, 4};
    int n = 7;
    int sum = 0, max = 0;
    for (int i = 0; i < n; i ++) {
        sum += a[i];
        if ( sum < 0 )  sum = 0;
        if ( max < sum )    max = sum;
    }
    printf("%d\n", max);
    return 0;
}
