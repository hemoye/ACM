#include <stdio.h>
#include <string.h>
#define  MAX 10+1

int main( void )
{
    char x[MAX];
    char HH[MAX], MM[MAX], SS[MAX];

    fgets(x, MAX, stdin);

    sscanf(x, "%[0-9]:%[0-9]:%[0-9]", &HH, &MM, &SS);
    //�ر�ֵ��ע����ǣ�sscanf�Ǵ��ַ����ж����ַ�����һ����Ҫ�������ַ���ʽ����˵����������һ�������Ľ�����־����ʱ�ı�־����:

    printf("%s, %s, %s\n", HH, MM, SS);

    return 0;
}
