#include <stdio.h>
#include <malloc.h>

typedef struct
{
    int age;
    char name[31];
} Node;

int main(void)
{
    int i;
    FILE * fq;
    Node student[2], other[2], * p1, * p2;

    //student = (Node *)malloc(2 * sizeof(Node));

    if ((fq = fopen("格式字符串的用法.txt", "w+")) == NULL)
    {
        printf("无效的文件路径！\n");
        getch();
        exit(1);
    }
//    fputs("姓名\t年龄\n", fq);
//    rewind(fq);
    for (i = 0; i < 2; i++)
        scanf("%s%d", student[i].name, &student[i].age);

    p1 = student;
    for (i = 0; i < 3; i++, p1++)
        fscanf(fq, "%s%d\n", p1[i].name, p1[i].age);

    rewind(fq);

    p2 = other;
    for (i = 0; i < 2; i++, p2++)
        fprintf(fq, "%s%d\n", p2[i].name, p2[i].age);

    fclose(fq);
    for (i = 0; i < 2; i++)
        printf("%s\t%d\n", p2[i].name, p2[i].age);

    return 0;
}
