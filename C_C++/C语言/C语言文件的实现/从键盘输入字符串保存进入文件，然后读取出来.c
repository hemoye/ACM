#include <stdio.h>

int main(void)
{
    FILE * fq;//��������������һ���ļ�ָ�루ָ���ļ���ָ�룩
    char ch;

    if ((fq = fopen("string", "wt+")) == NULL)//���ļ�
    {
        printf("û�д��ļ���·��!\n");
        getch();
        exit(1);//������ֹ����
    }
    ch = getchar();//һ��һ���������ַ���
    while (ch != '\n')
    {
        fputc(ch, fq);//���ַ�����ָ������
        ch = getchar();
    }
    rewind(fq);//�ص��ļ���ͷ
    ch = fgetc(fq);//����ļ��еĵ�һ���ַ�
    while (ch != EOF)
    {
        putchar (ch);//����ļ��е�����
        ch = fgetc(fq);
    }
    printf("\nThere are %d char in the title!\n", ftell(fq));//ftell���÷�:��ò������ļ����ַ��ĸ���
    fclose(fq);//�ر��ļ�

    return 0;
}
