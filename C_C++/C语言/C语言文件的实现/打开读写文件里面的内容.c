#include <stdio.h>
#include <stdlib.h>

int main(Void)
{
    FILE * fq;//定义一个文件指针
    char ch;

    if ((fq = fopen("打开读写文件里面的内容(打开本文件夹中的内容).c", "rt")) == NULL)//此种情况下只需要用文件名即可
    {
        printf("无效的文件路径！\n");
        getch();
        exit(1);
    }
    ch = fgetc(fq);//获得文件中的第一个字符
    while (ch != EOF)
    {
        putchar (ch);//输出获得的字符
        ch = fgetc(fq);
    }
    fclose(fq);//关闭文件

    return 0;
}
