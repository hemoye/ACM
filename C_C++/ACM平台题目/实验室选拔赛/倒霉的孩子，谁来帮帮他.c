#include<stdio.h>
#include<string.h>

int main(void)
{
    int k,i,j,n,m,flag1,flag2,len;
    k = 1;
    char str[100],arr[100];

    while (scanf("%s%s",str,arr)!=EOF)
    {
        m = 0;
        len = strlen(arr);
        if (strcmp(str,"#")==0 && strcmp(arr,"#")==0)
            break;
        for (i = 0; str[i]!='\0'; i++)
        {
            flag1 = 1;
            flag2 = 0;
            if (str[i]==arr[0])
            {
                flag2 = 1;
                for (j = 1; j < len; j++)
                    if (str[i+j]!=arr[j])
                        flag1 = 0;
            }
            if (flag1==1&&flag2==1)
            {
                m++;
                for (n = i; str[len+n]!='\0'; n++)
                    str[n] = str[len+n];
                str[n] = '\0';
                i = -1;
            }
        }
        printf("Case %d:\n",k++);
        printf("%s\n",str);
        printf("%d\n",m);
    }
    return 0;
}
/*
���˶����������Լ����������֡�

AaronҲ�����⣬����������������˵Ĳ��Ҵ�����������һ��������ɣ�



Input

���������ж��飬ÿ�����ݺ������ַ�����ÿ�����Ȳ�����150�����ڶ���Ϊ���Ҵ����������ַ���������Ϊ��#��ʱ���������������������
Output

����ÿ����Խ�����������"Case i: ",i��ʾ�ڼ�����Խ��.��������������޳����Ҵ�֮�����õ������ַ������޳����Ҵ�����Ĵ�����(����޳�һ�����Ҵ���ʣ�µ��ַ��������һ�����Ҵ��������ɾ����
Sample Input

ABABABANDABABA ABA
Aarrononswrong ron
Maryaraaarrrgototheclass ar
# #
Sample Output

Case 1:
BNDBA
3
Case 2:
Aaswg
3
Case 3:
Mygototheclass
5
*/
