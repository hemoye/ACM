#include <stdio.h>
#include <math.h>
int main(void)
{
    float judge_1(float x);//��������
    float judge_2(float x);

    float a, b, c, x1, x2, detal;//��������

    scanf("%f %f %f", &a, &b, &c);//����һԪ���η��̵ĸ���ϵ��
    detal = b * b - 4 * a * c;//��һԪ���η����б�ʽ��ֵ
    if (detal >= 0)//����б�ʽ����0�����judge_1
    {
        x1 = (-b + judge_1(detal)) / (2 * a);
        x2 = (-b - judge_1(detal)) / (2 * a);
        printf("%.2f %.2f\n", x1, x2);
    }
    else//�������judge_2
    {
        x1 = (-b) / (2 * a);
        x2 = judge_2(detal) / (2 * a);
        printf("%.2f+%.2fi %.2f-%.2fi\n", x1, x2, x1, x2);
    }

    return 0;
}
float judge_1(float x)
{
    x = sqrt(x);

    return x;
}
float judge_2(float x)
{
    x = sqrt(-x);

    return x;
}
