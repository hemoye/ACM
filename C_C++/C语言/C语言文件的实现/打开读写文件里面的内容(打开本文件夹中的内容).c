#include <stdio.h>
#include <stdlib.h>

int main(Void)
{
    FILE * fq;
    char ch;

    if ((fq = fopen("F://ACM平台题目//学生管理系统.c", "rt")) == NULL)//此种情况下
    {//格式是：某盘://文件夹名字//文件夹名字//...直到找到直接包含所需文件的文件夹
        printf("无效的文件路径！\n");
        getch();
        exit(1);
    }
    ch = fgetc(fq);
    while (ch != EOF)
    {
        putchar (ch);
        ch = fgetc(fq);
    }
    fclose(fq);

    return 0;
}
