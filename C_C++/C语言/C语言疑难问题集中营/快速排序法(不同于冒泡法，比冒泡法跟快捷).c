#include<stdio.h>//头文件
main()
{
    int a[100],i,j, n,T,k;//变量声明
    scanf("%d",&T);//控制循环组数
    for(k=1; k<=T; k++)//控制循环
    {
        scanf("%d",&n);//控制数组实际长度

        for(i=1; i<=n; i++)//输入数组
            scanf("%d",&a[i]);

        for(i=2; i<=n; i++)//XX法排序
        {
            a[0]=a[i];//把第i个值放在数组的首位置
            j=i-1;//取标记数字的前一个数字

            while(a[j]>a[0])//当两者比较且返回真时执行循环
            {
                a[j+1]=a[j];//这时候a[j]的值推后一位
                j--;//判断数字继续往前推进
            }
            a[j+1] = a[0];//并且把首位置的值覆盖在a[j]的位置上面
        }

        for(i=1; i<=n; i++)//输出排序后的数字
            printf("%d ",a[i]);
        printf("\n");
    }
}
