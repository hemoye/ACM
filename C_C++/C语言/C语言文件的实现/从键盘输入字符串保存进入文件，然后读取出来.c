#include <stdio.h>

int main(void)
{
    FILE * fq;//定义声明，定义一个文件指针（指向文件的指针）
    char ch;

    if ((fq = fopen("string", "wt+")) == NULL)//打开文件
    {
        printf("没有打开文件的路径!\n");
        getch();
        exit(1);//意外终止程序
    }
    ch = getchar();//一个一个的输入字符串
    while (ch != '\n')
    {
        fputc(ch, fq);//把字符存入指针里面
        ch = getchar();
    }
    rewind(fq);//回到文件开头
    ch = fgetc(fq);//获得文件中的第一个字符
    while (ch != EOF)
    {
        putchar (ch);//输出文件中的内容
        ch = fgetc(fq);
    }
    printf("\nThere are %d char in the title!\n", ftell(fq));//ftell的用法:获得并返回文件中字符的个数
    fclose(fq);//关闭文件

    return 0;
}
