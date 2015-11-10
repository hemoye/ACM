#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, z, m, n, x;
    char a[1001], b[1001];//声明语句

    scanf("%d", &m);//输入需要转化的进制
    for (z = 1; z <= 300; z++)//1~300所有的数字
    {
        int flage = 1, j = 0, k = 0;
        n = z * z;
        x = z;

        while (n)
        {
            a[j++] = n % m + '0';
            n /= m;
        }

        for (i = j - 1, n = 0; i >= 0; i--, n++)
            if (a[i] != a[n])
            {
                flage = 0;
                break;
            }
        if (flage)
        {
            while (x)
            {
                b[k++] = x % m + '0';
                x /= m;
            }

            for (i = k - 1; i >= 0; i--)
            {
                switch (b[i] - '0')
                {
                case 10:
                    printf("A");
                    break;
                case 11:
                    printf("B");
                    break;
                case 12:
                    printf("C");
                    break;
                case 13:
                    printf("D");
                    break;
                case 14:
                    printf("E");
                    break;
                case 15:
                    printf("F");
                    break;
                case 16:
                    printf("G");
                    break;
                case 17:
                    printf("H");
                    break;
                case 18:
                    printf("I");
                    break;
                case 19:
                    printf("J");
                    break;
                default :
                    printf("%c", b[i]);
                }
            }
            printf(" ");
            for (i = j - 1; i >= 0; i--)
            {
                switch (a[i] - '0')
                {
                case 10:
                    printf("A");
                    break;
                case 11:
                    printf("B");
                    break;
                case 12:
                    printf("C");
                    break;
                case 13:
                    printf("D");
                    break;
                case 14:
                    printf("E");
                    break;
                case 15:
                    printf("F");
                    break;
                case 16:
                    printf("G");
                    break;
                case 17:
                    printf("H");
                    break;
                case 18:
                    printf("I");
                    break;
                case 19:
                    printf("J");
                    break;
                default :
                    printf("%c", a[i]);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
