#include <stdio.h>

int main(void)
{
    void inputFunction(int * );
    void Deal(int * );
    void outputFunction(int * );

    int a[10];

    inputFunction(a);
    Deal(a);
    outputFunction(a);

    return 0;
}
void inputFunction(int * a)//���뺯��
{
    int i = 0;

    while(scanf("%d",&a[i]) != EOF )
        i++;
}
void Deal(int * a)//������
{
    int i, j, min, max, temp;
    int nummax = 0, nummin = 0;

    min = max =a[0];
    for (i = 0; i < 10; i++)//�ҳ����ֵ
        if (max < a[i])
        {
            max = a[i];
            nummax = i;
        }
    for (i = 0; i < 10; i++)//�ҳ���Сֵ
        if (min > a[i])
        {
            min = a[i];
            nummin = i;
        }
    if (nummin == 9 && nummax == 0)
    {
        temp = a[nummin];
        a[nummin] = a[nummax];
        a[nummax] = temp;
    }
    else if (!(nummin == 0 && nummax == 9))
    {
        temp = a[0];
        a[0] = a[nummin];
        a[nummin] = temp;

        temp = a[9];
        a[9] = a[nummax];
        a[nummax] = temp;
    }

    return 0;
}
void outputFunction(int * a)//�������
{
    int i;

    for (i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
