#include <stdio.h>

int main(void)
{
    char str[101];//�����ַ�����
    int i;//�������

    scanf("%s", str);//�����ַ�������

    for (i = strlen(str) - 1; i >= 0; i--)//�������
    {
        if (str[i] >= '0' && str[i] <= '9')
            str[i] = '9' - str[i] + '0';
        else if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
    for (i = strlen(str) - 1; i >= 0; i--)
        printf("%c", str[i]);
    printf("\n");

    return 0;
}
