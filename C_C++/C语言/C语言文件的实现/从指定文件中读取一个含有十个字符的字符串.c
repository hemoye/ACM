#include <stdio.h>

int main(void)
{
    FILE * fq;//��������������һ���ļ�ָ��
    char str[11];

    if ((fq = fopen("����.c", "r")) == NULL)
    {
        printf("û�пɹ����ļ���·��!\n");
        getch();
        exit (1);
    }
    fgets(str, 11, fq);//��ȡһ��ʮ�����ȵ��ַ���
    //fgets����Ҳ�з���ֵ���䷵��ֵ���ַ�������׵�ַ
    puts(str);//�����ȡ�����ַ���
    fclose(fq);//�ر��ļ�

    return 0;
}
