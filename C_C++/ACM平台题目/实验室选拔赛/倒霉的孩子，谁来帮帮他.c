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
个人都有着属于自己的幸运数字。

Aaron也不例外，这里有许多会带来厄运的不幸串，快来帮他一个个消灭吧！



Input

测试数据有多组，每组数据含两个字符串（每个长度不超过150），第二个为不幸串（当两个字符串都输入为“#”时，输入结束，不做处理）。
Output

对于每组测试结果，首先输出"Case i: ",i表示第几组测试结果.接下来两行输出剔除不幸串之后所得到的新字符串与剔除不幸串所需的次数。(如果剔除一个不幸串后剩下的字符又组成了一个不幸串，则继续删除）
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
