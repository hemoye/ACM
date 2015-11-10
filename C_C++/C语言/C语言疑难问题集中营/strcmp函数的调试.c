#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[10], str2[10];
    scanf("%s%s", str1, str2);

    printf("%d", strcmp(str1, str2));

    return 0;
}
/*在clodblacks输出的结果是：
*************************
1
*************************
结论：只有当两个字符串完全相同时strcmp函数才回返回0
      当前面的字符串所代表的数值大于后面的字符串时返回1
      当前面的字符串所代表的数值后小于面的字符串时返回-1
*/
