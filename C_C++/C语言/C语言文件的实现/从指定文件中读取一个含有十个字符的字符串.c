#include <stdio.h>

int main(void)
{
    FILE * fq;//定义声明，定义一个文件指针
    char str[11];

    if ((fq = fopen("豪哥.c", "r")) == NULL)
    {
        printf("没有可供打开文件的路径!\n");
        getch();
        exit (1);
    }
    fgets(str, 11, fq);//读取一个十个长度的字符串
    //fgets函数也有返回值，其返回值是字符数组的首地址
    puts(str);//输出读取到的字符串
    fclose(fq);//关闭文件

    return 0;
}
