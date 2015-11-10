#include <cstdio>

int main(int agrc, char *agrv[])
{
    int n;

    scanf("%d", &n);

    while (n--){
        char count;
        int a, b;

        scanf(" %c %d %d", &count, &a, &b);
        switch (count){
        case '+' : printf("%d\n", a + b);
            break;
        case '-' : printf("%d\n", a - b);
            break;
        case '*' : printf("%d\n", a * b);
            break;
        case '/' :
            if (a / b * b == a) printf("%d\n", a / b);
            else printf("%.2f\n", (float)a / b);
            break;
        }
    }

    return 0;
}
