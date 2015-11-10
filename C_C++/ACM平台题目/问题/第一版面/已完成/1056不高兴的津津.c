#include <stdio.h>

int main(void)
{
    int day, time1, time2, time[7];

    for (day = 0; day < 7; day++)
    {
        scanf("%d %d", &time1, &time2);
        time[day] = time1 + time2;
    }

    time2 = 1;
    for (day = 0; day < 7; day++)
        if(time[day] > time[0])
        {
            time2 = day + 1;
            time[0] = time[day];
        }

    printf("%d\n", time2);

    return 0;
}
