#include <stdio.h>

int main(void)
{
    int a;
    long b;
    long long c;

    while (scanf("%d %ld %lld", &a, &b, &c) != EOF)
        printf("%d %ld %lld\n", a, b, c);

    return 0;
}
/*��clodblacks�Ľ���ǣ�
int��long�����Խ���10λ����
long long���Խ���19λ����
*/
