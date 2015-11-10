#include <stdio.h>

int main(void)
{
    int year, month, day, time;

    while (scanf("%d-%d-%d", &year, &month, &day) != EOF)
    {
        if (month == 1)
            time = day;
        else if (2 == month)
            time = day + 31;
        else
        {
            switch (month)
            {
            case 3:
                time = 59 + day;
                break;
            case 4:
                time = 90 + day;
                break;
            case 5:
                time = 120 + day;
                break;
            case 6:
                time = 151 + day;
                break;
            case 7:
                time = 181 + day;
                break;
            case 8:
                time = 212 + day;
                break;
            case 9:
                time = 242 + day;
                break;
            case 10:
                time = 273 + day;
            case 11:
                time = 303 + day;
            default :
                time = 334 + day;
            }
            if (year % 400 == 0 && (year % 4 == 0 && year % 100 != 0))
                time += 1;
        }
        printf("%d\n", time);
    }

    return 0;
}
