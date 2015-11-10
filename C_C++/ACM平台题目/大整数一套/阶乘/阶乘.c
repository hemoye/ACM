#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100];
    int i, j, k, len, z = 0;
    unsigned x;

    while (scanf("%u", &x) && 0 != x)
    {
        int a[40000]= {0},b[40000]= {0},c[40000]= {0};
        if (0 == x)
           break;
        b[0] = 1;/*初始化b,求阶乘从1开始*/
        len = 1;/*初始化b的长度*/
        for(i = 1; i <= x; i++) /*阶乘从低往高乘*/
        {
            sprintf(str,"%d",i);/*将阶乘项转换为字符串*/

            for(j = strlen(str) - 1; j >= 0; j--) /*逆向存储阶乘项(串)*/
                a[strlen(str)-1-j] = str[j] - '0';/*注意要变成整数才能进行相乘*/

            for(j = 0; j < len; j++) /*取b的所有位*/
                for(k = 0; k < strlen(str); k++) /*取阶乘项的每一位*/
                {
                    c[j+k] += b[j] * a[k];/*用c来存储每一位相乘的结果*/
                    c[j+1+k] +=c[j+k] / 10;/*若c[j+k]不小于10,则将大于10的部分送至高位*/
                    c[j+k] %= 10;/*送至高位后,c[j+k]应作相应的求余运算。只保留剩余部分*/
                }
            if(c[j+k-1])/*判断新的b数的位数长度*/
                len = j+k;
            else
                len = j+k-1;
            for(j = 0; j < len; j++) /*将b更新*/
                b[j] = c[j];
            memset(c, 0, 10000);/*将c归零*/
        }
        printf("Case #%d:\n", ++z);
        for(i = len - 1; i >= 0; i--) /*逆向输出结果*/
            printf("%d", b[i]);
        printf("\n");
        memset(str, '0', 10);
    }

    return 0;
}
