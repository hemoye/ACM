#include <stdio.h>
#define PI 3.14
int main(void)
{
    float r, h;
    float C, S1, S2, V1, V2;

    scanf("%f %f", &r, &h);
    C = 2 * PI * r;//Բ�ܳ�
    S1 = PI * r * r;//Բ���
    S2 = 4 * PI * r * r;//������
    V1 = PI * r * r * r * 4 / 3;//�����
    V2 = S1 * h;//Բ�����

    printf("%.2f %.2f %.2f %.2f %.2f\n", C, S1, S2, V1, V2);
}
