#include <stdio.h>
#include <stdlib.h>

int main(Void)
{
    FILE * fq;//����һ���ļ�ָ��
    char ch;

    if ((fq = fopen("�򿪶�д�ļ����������(�򿪱��ļ����е�����).c", "rt")) == NULL)//���������ֻ��Ҫ���ļ�������
    {
        printf("��Ч���ļ�·����\n");
        getch();
        exit(1);
    }
    ch = fgetc(fq);//����ļ��еĵ�һ���ַ�
    while (ch != EOF)
    {
        putchar (ch);//�����õ��ַ�
        ch = fgetc(fq);
    }
    fclose(fq);//�ر��ļ�

    return 0;
}
