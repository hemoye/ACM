/*
�ڡ��Ӽ��������ַ�����������ļ���Ȼ���ȡ����������
���������ļ���׷���ַ���
*/
#include <stdio.h>

int main(void)
{
    FILE * fq;
    char ch, str[21];

    if ((fq = fopen("string", "a+")) == NULL)
    {
        printf("��Ч���ļ�·��!\n");
        getch();
        exit(1);
    }
    scanf("%s", str);
    fputs(str, fq);//C������Ĭ��׷�����ļ���ĩβ
    rewind(fq);//�����ļ��Ŀ�ʼ
    ch = fgetc(fq);
    while (ch != EOF)
    {
        putchar(ch);
        ch = fgetc(fq);
    }
    fclose (fq);//�ر��ļ�

    return 0;
}
