#include <stdio.h>
#include <stdlib.h>

int main(Void)
{
    FILE * fq;
    char ch;

    if ((fq = fopen("F://ACMƽ̨��Ŀ//ѧ������ϵͳ.c", "rt")) == NULL)//���������
    {//��ʽ�ǣ�ĳ��://�ļ�������//�ļ�������//...ֱ���ҵ�ֱ�Ӱ��������ļ����ļ���
        printf("��Ч���ļ�·����\n");
        getch();
        exit(1);
    }
    ch = fgetc(fq);
    while (ch != EOF)
    {
        putchar (ch);
        ch = fgetc(fq);
    }
    fclose(fq);

    return 0;
}
