#include <stdio.h>

void Leap(int );

int main(void)
{
    int n;

    scanf("%d", &n);
    Leap(n);

    return 0;
}
void Leap(int n)
{
    if (n == 2)
    {
        printf("Move disk 1 from A to B Move disk 2 ");
        printf("from A to C Move disk 1 from B to C\n");
    }
    else
    {
        printf("Move disk 1 from A to B Move disk 2 ");
        printf("from A to C Move disk 1 from B to C\n");

        Leap(n-1);
    }
}
