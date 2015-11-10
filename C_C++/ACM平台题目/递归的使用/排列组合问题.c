#include <stdio.h>
#define swap(a, b, t) t = a, a = b, b = t
#define MAX 100

int array[MAX];

void perm(int mark, int m)
{
    int i, t;

    if (mark == m - 1)
    {
        for (i = 0; i < m; i++)
            printf("%d", array[i]);
        puts("");
    }
    else
    {
        for (i = mark; i < m; i++)
        {
            swap(array[mark], array[i], t);
            perm(mark + 1, m);
            swap(array[mark], array[i], t);
        }
    }
    return ;
}

int main(void)
{
    int i, n;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        array[i] = i + 1;

    perm(0, n);

    return 0;
}
