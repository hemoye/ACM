#include <stdio.h>

struct stu
{
    char name[10];
    int num;
    int age;
    char addr[21];
} boya[2], boyb[2], *pp;
int main(void)
{
    FILE * fq;
    char ch;
    int i;
    pp = boya;
    if ((fq = fopen("stu_list.txt", "wt+")) == NULL)
    {
        printf("无效的文件路径!\n");
        getch();
        exit(1);
    }
    for (i = 0; i < 2; i++, pp++)
        scanf("%s%d%d%s", pp->name, &pp->num, &pp->age, pp->addr);
    pp = boya;
    fwrite(pp, sizeof(struct stu), 2, fq);
    rewind(fq);
    pp = boyb;
    fread(pp, sizeof(struct stu), 2, fq);
    printf("\n\nname\tnumber\tage\taddr\n");
    for (i = 0; i < 2; i++, pp++)
        printf("%s\t%d\t%d\t%s\n", pp->name, pp->num, pp->age, pp->addr);
    fclose(fq);

    return 0;
}
