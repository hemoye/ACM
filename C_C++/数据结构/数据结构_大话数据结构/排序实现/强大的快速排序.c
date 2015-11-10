#include <stdio.h>

void Quick(int *, int , int );
int FindPos(int *, int , int );

int main(void)
{
    int i;
    int a[] = {4, 9, -11, 1, 0, 1, 2, -116};

    Quick(a, 0, 7);

    for (i = 0; i < 8; i++)
        printf("%d  ", a[i]);
    puts("");

    return 0;
}
void Quick(int * a, int low, int high)
{
    int pos;

    if (low < high)
    {
        pos = FindPos(a, low, high);
        Quick(a, low, pos-1);
        Quick(a, pos+1, high);
    }
}
int FindPos(int * a, int low, int high)
{
    int val = a[low];

    while(low < high)
    {
        while (low < high && a[high] >= val)
            high--;
        a[low] = a[high];

        while (low < high && a[low] <= val)
            low++;
        a[high] = a[low];
    }
    a[low] = val;

    return high;
}
