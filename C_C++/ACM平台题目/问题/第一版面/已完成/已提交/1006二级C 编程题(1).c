#include <stdio.h>
int main(void)
{
    int gread;//�������
    int num1 = 0, num2 = 0, num3 = 0;//��������ֵ���

    while (scanf("%d", &gread) != EOF)
    {
        if (gread <= 0)
            break;
        if (gread >= 85)//ͳ�����������
            num1++;
        if (gread >= 60 && gread < 85)//ͳ��ͨ��������
            num2++;
        else if (gread < 60 && gread > 0)//ͳ�Ʋ����������
            num3++;
    }

    printf(">=85:%d\n60-84:%d\n<60:%d\n", num1, num2, num3);
    //���ͳ������
    return 0;
}
