#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[20];//����һ���ַ�����
    int a[20] = {0}, b[2] = {0};//���岢��ʼ��������������
    char money[9][10] = {"Ԫ","ʮ","��","ǧ","��","ʮ","��","ǧ","��"};
    char number[11][10] = {"��","Ҽ","��","��","��","��","½","��","��","��","ʰ"};
    int i, j, x = 0, flage = 0;

    scanf("%s", str);

    for (i = 0; i < strlen(str); i++)
        if (str[i] == '.')
        {
            flage = 1;
            b[0] = str[i+1] - '0';//ȡ��С�������ĵ�һλ����
            b[1] = str[i+2] - '0';//ȡ��С�������ڶ�λ������
            break;
        }
        else
        {
            a[i] = str[i] - '0';//����ȡ��С����ǰ�����������
            x++;
        }
    for (i = 0; i < x; i++)
    {
        if (strcmp (number[a[i]],number[a[i+1]]) == 0)
            continue;
        else
        {
            printf("%s", number[a[i]]);
            printf("%s", money[x-i-1]);
        }
    }

    return 0;
}
