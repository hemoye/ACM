#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[10], str2[10];
    scanf("%s%s", str1, str2);

    printf("%d", strcmp(str1, str2));

    return 0;
}
/*��clodblacks����Ľ���ǣ�
*************************
1
*************************
���ۣ�ֻ�е������ַ�����ȫ��ͬʱstrcmp�����Żط���0
      ��ǰ����ַ������������ֵ���ں�����ַ���ʱ����1
      ��ǰ����ַ������������ֵ��С������ַ���ʱ����-1
*/
