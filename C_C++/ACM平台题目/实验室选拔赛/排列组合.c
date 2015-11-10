#include <stdio.h>
#define MAX 1000
#define swap(a, b, t) t = a, a = b, b = t

int arr[1000];
int num = 0;

void perm(int first, int len)
{
    int i, temp;

    if (first < len)
    {
        for (i = first; i < len; i++)
        {
            printf("%d->xiemei\n", num++);
            swap (arr[first], arr[i], temp);
            perm(first + 1, len);

            swap (arr[first], arr[i], temp);
        }
    }
    else
    {
        for (i = 0; i < len; i++)
            printf("%d", arr[i]);
        puts("");
    }
    return ;
}

int main(void)
{
    int i, n;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        arr[i] = i + 1;

    perm(0, n);

    return 0;
}
