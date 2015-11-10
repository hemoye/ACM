#include <stdio.h>
int main(void)
{
    int gread, t;

    scanf("%d", &gread);
    t = gread / 10;

    switch (t)
    {
    case 1 :
    case 2 :
    case 3 :
    case 4 :
    case 5 :
        printf("E\n");
        break;
    case 6 :
        printf("D\n");
        break;
    case 7 :
        printf("C\n");
        break;
    case 8 :
        printf("B\n");
        break;
    case 9 :
    case 10 :
        printf("A\n");
        break;
    default :
        printf("The score is error!\n");
        break;
    }
}
