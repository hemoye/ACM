#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100];
    int i, j, k, len, z = 0;
    unsigned x;

    while (scanf("%u", &x) && 0 != x)
    {
        int a[40000]= {0},b[40000]= {0},c[40000]= {0};
        if (0 == x)
           break;
        b[0] = 1;/*��ʼ��b,��׳˴�1��ʼ*/
        len = 1;/*��ʼ��b�ĳ���*/
        for(i = 1; i <= x; i++) /*�׳˴ӵ����߳�*/
        {
            sprintf(str,"%d",i);/*���׳���ת��Ϊ�ַ���*/

            for(j = strlen(str) - 1; j >= 0; j--) /*����洢�׳���(��)*/
                a[strlen(str)-1-j] = str[j] - '0';/*ע��Ҫ����������ܽ������*/

            for(j = 0; j < len; j++) /*ȡb������λ*/
                for(k = 0; k < strlen(str); k++) /*ȡ�׳����ÿһλ*/
                {
                    c[j+k] += b[j] * a[k];/*��c���洢ÿһλ��˵Ľ��*/
                    c[j+1+k] +=c[j+k] / 10;/*��c[j+k]��С��10,�򽫴���10�Ĳ���������λ*/
                    c[j+k] %= 10;/*������λ��,c[j+k]Ӧ����Ӧ���������㡣ֻ����ʣ�ಿ��*/
                }
            if(c[j+k-1])/*�ж��µ�b����λ������*/
                len = j+k;
            else
                len = j+k-1;
            for(j = 0; j < len; j++) /*��b����*/
                b[j] = c[j];
            memset(c, 0, 10000);/*��c����*/
        }
        printf("Case #%d:\n", ++z);
        for(i = len - 1; i >= 0; i--) /*����������*/
            printf("%d", b[i]);
        printf("\n");
        memset(str, '0', 10);
    }

    return 0;
}
