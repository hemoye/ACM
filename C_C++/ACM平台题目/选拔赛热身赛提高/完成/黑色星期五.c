#include <stdio.h>
int Judge(int year)
{
    if (year%400==0 || (year%4==0&&year%100!=0))
        return 1;
    else
        return 0;
}
int main(void)
{
    int i, j, z, n, x, sum = 0, num = 0, count[7] = {0};//һ�δ洢����һ��������
    int day[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
    scanf("%d", &n);
    for (i = 1900; i < 1900 + n; i++)
    {
        j = Judge(i);//�ж��Ƿ�������
        for (z = 0; z < 12; z++)
        {
            num = sum + 13;//
            count[num%7]++;//����ÿһ���µ�13�������ڼ�
            sum += day[j][z];//�ۼ�ÿһ���µ�����
        }
    }
    printf("%d %d", count[6], count[0]);//�����������������
    for (i = 1; i <= 5; i++)
        printf(" %d", count[i]);//�����������һ��������
    printf("\n");
    return 0;
}
