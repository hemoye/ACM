#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[1000], str2[1000];//���������ַ�����
    int a[1000] = {0};//����һ������
    int i, j, len;//�������

    scanf("%s%s", str1, str2);//���������ַ���

    for (i = 0; i < strlen(str1); i++)//�ۼӸ���λ���ϳ˻��ĺ�
        for (j = 0; j < strlen(str2); j++)
            a[i+j+1] += (str1[i] - '0') * (str2[j] - '0');//a[0]��Ϊ���λ

    for (len = strlen(str1) + strlen(str2) - 1; len > 0; len--)
        while (a[len] > 9)
        {
            a[len-1] += a[len] / 10;//ʮ���ƴ���10�ͽ�һ
            a[len] %= 10;
        }

    if (a[0])//������λ����0�����
        printf("%d", a[0]);
    for (i = 1; i < strlen(str1) + strlen(str2); i++)//����˻���ֵ
        printf("%d", a[i]);
    printf("\n");

    return 0;
}
