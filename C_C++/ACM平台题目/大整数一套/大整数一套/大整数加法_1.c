#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, j, k, max, s, sum;//�������
    int a[1000] = {0}, b[1000] = {0};//��������
    char s1[1000], s2[1000];//�����ַ�������

    scanf ("%s%s", s1, s2);//�����ַ���

    k = max = (strlen(s1) > strlen(s2)) ? strlen(s1) : strlen(s2);//ȡ�������ַ�������

    for(i = k,j = strlen(s1) - 1; j >= 0; i--, j--)//���ַ�ת�����洢��������
        a[i] = s1[j] - '0';
    for(i = k, j = strlen(s2) - 1; j >= 0; i--, j--)//���ַ�ת�����洢��������
        b[i] = s2[j] - '0';
    for(i = k; i > 0; i--)//ѭ���ۼӸ���λ�����������
    {
        a[i] += b[i];
        if(a[i] > 9)//ʮ���ƣ�������ִ���10�����һ��
        {
            a[i] -= 10;
            a[i-1]++;
        }
    }

    if(a[0])//�����һλ����0�������
        for(i = 0; i <= k; i++)
            printf("%d",a[i]);
    else//����ӵڶ������ֿ�ʼ���
        for(i=1; i<=k; i++)
            printf("%d",a[i]);

    return 0;
}
