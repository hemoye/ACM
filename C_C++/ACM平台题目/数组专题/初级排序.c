#include <stdio.h>

int main(void)
{
    int index, jeans, temp, a[3];

    for (index = 0; index < 3; index++)
        scanf("%d", &a[index]);

    for (index = 0; index < 3; index++)
        for (jeans = 0; jeans < 2 - index; jeans++)
            if (a[jeans] > a[jeans+1])
            {
                temp = a[jeans];
                a[jeans] = a[jeans+1];
                a[jeans+1] = temp;
            }
    printf("%d %d %d \n", a[0], a[1], a[2]);

    return 0;
}
