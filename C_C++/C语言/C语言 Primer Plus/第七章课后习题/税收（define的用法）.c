#include <stdio.h>
#define shui1 0.15
#define shui2 0.20

int main(void)
{
    float time, money;

    while (scanf("%f", &time) == 1)
    {
        if (time > 40)
            time = time * 1.5;
        if (time <= 300)
            money = time * 8.5;
        else if (time > 300 && time < 450)
            money = 300 * 8.5 + (time - 300) * 8;
        else
            money = 300 * 10 * 0.85 + 10 * 0.8 + (time - 550) * 10 * 7.5;
        printf("%.2f\n", money);
    }

    return 0;
}
