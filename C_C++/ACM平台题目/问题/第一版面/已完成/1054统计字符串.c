#include <stdio.h>
#include <string.h>
int main(void)
{
    char str1[100], str2[10];
    int i, j, sum, num = 0;//�������

    gets (str1);//����һ���ַ���
    gets (str2);//����ڶ����ַ���

    for (i = 0; i < strlen(str1); )
    {
        sum = 0;
        for (j = 0; j < strlen(str2); j++)
            if (str1[i++] == str2[j])
                sum++;
        --i;
        if (strlen(str2) == sum)
            num++;
    }
    printf("%d\n", num);

    return 0;
}
