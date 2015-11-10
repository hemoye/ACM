/*
在“从键盘输入字符串保存进入文件，然后读取出来”程序
所产生的文件中追加字符串
*/
#include <stdio.h>

int main(void)
{
    FILE * fq;
    char ch, str[21];

    if ((fq = fopen("string", "a+")) == NULL)
    {
        printf("无效的文件路径!\n");
        getch();
        exit(1);
    }
    scanf("%s", str);
    fputs(str, fq);//C语言中默认追加在文件的末尾
    rewind(fq);//返回文件的开始
    ch = fgetc(fq);
    while (ch != EOF)
    {
        putchar(ch);
        ch = fgetc(fq);
    }
    fclose (fq);//关闭文件

    return 0;
}
