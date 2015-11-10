#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 401
#define MM student[i].number, student[i].name, student[i].banji, student[i].minzu, student[i].sex, student[i].age, student[i].nian, student[i].yue, student[i].zhuanye
#define NN &student[len].number,student[len].name,&student[len].banji,student[len].minzu,student[len].sex,&student[len].age,&student[len].nian,&student[len].yue,student[len].zhuanye
#define geshi printf("|————————————————————————————————————|\n")

int len = 0;

struct stud//定义结构体
{
    int nian;//出生的年份
    int yue;//出生的月份
    int age;//用于存储年龄
    int number;//用于存储学号
    int banji;
    char minzu[31];
    char name[31];//用于存储名字
    char sex[31];//性别
    char zhuanye[31];//专业
} student[MAX];

void shuru(void)
{
    int i, j, x = 0;
    int num = len;

    for (i = 0; i < num; i++)
    {
a:
        printf("请输入第%d个学生的学号:\n", i + 1);
        scanf ("%d", &student[i].number);//学号
        for (j = 0; j < i; j++)
            if (student[i].number == student[j].number)
            {
                printf("您输入的学号已存在！请重新输入！\n");
                goto a;
            }
        printf("请输入第%d个学生的名字:\n", i + 1);
        scanf ("%s", student[i].name);//名字
        printf("请输入第%d个学生的性别:\n", i + 1);
        scanf ("%s", student[i].sex);//性别
        printf("请输入第%d个学生的所属的民族:\n", i + 1);
        scanf ("%s", student[i].minzu);//民族
        printf("请输入第%d个学生的所在的班级(本模块只支持数字输入):\n", i + 1);
        scanf("%d", &student[i].banji);//班级
        printf("请输入第%d个学生的年龄:\n", i + 1);
        scanf ("%d", &student[i].age);//年龄
        printf("请输入第%d个学生的出生年月（以空格隔开）:\n", i + 1);
        scanf ("%d %d", &student[i].nian, &student[i].yue);//出生年月
        printf("请输入第%d个学生的所在的专业:\n", i + 1);
        scanf ("%s", student[i].zhuanye);//专业
        system("cls");
    }
    shuchu();
}
void paixu(void)
{
    int i, j, flage;
    struct stud temp;

    printf("请输入您想要的排序方式：\n");
    printf("1.按学号顺序从小到大排序\n");
    printf("2.按出身年月从小到大排序\n");
    printf("3.按年龄从小到大排序\n");
    printf("4.按班级由小到大排序\n");

    scanf("%d", &flage);
    if (1 == flage)
    {
        for (i = 0; i < len; i++)
            for (j = 0; j < len - i - 1; j++)
                if (student[j].number > student[j+1].number)
                {
                    temp = student[j];
                    student[j] = student[j+1];
                    student[j+1] = temp;
                }
        printf("\n您所需要的排序方式如下:\n");
        shuchu();
    }
    else if (2 == flage)
    {
        for (i = 0; i < len; i++)
            for (j = 0; j < len - i - 1; j++)
                if (student[j].nian > student[j+1].nian)
                {
                    temp = student[j];
                    student[j] = student[j+1];
                    student[j+1] = temp;
                }
        for (i = 0; i < len; i++)
            for (j = 0; j < len - i - 1; j++)
                if (student[j].yue < student[j+1].yue)
                {
                    temp = student[j];
                    student[j] = student[j+1];
                    student[j+1] = temp;
                }
        printf("\n您所需要的排序方式如下:\n");
        shuchu();
    }
    else if (3 == flage)
    {
        for (i = 0; i < len; i++)
            for (j = 0; j < len - i - 1; j++)
                if (student[j].age > student[j+1].age)
                {
                    temp = student[j];
                    student[j] = student[j+1];
                    student[j+1] = temp;
                }
        printf("\n您所需要的排序方式如下:\n");
        shuchu();
    }
    else if (4 == flage)
    {
        for (i = 0; i < len; i++)
            for (j = 0; j < len - i - 1; j++)
                if (student[j].banji > student[j+1].banji)
                {
                    temp = student[j];
                    student[j] = student[j+1];
                    student[j+1] = temp;
                }
        printf("\n您所需要的排序方式如下:\n");
        shuchu();
    }
    else
        printf("\n本程序不支持您所选择的排序方式！\n");
}
void xiugai(void)//函数：修改指定学生的信息
{
    int i, num, flage = 0;
    char secret;

    shuchu();
    printf("\n请输入您要修改的学生的学号:\n\n");
    scanf("%d", &num);

    for (i = 0; i < len; i++)
        if (student[i].number == num)
        {
            flage = 1;
            break;
        }
    if (flage)
    {
        printf("您要修改的学生数据如下:\n\n");
        geshi;
        printf("|学号\t|姓名\t|班级\t|民族\t|性别\t|年龄\t|出生年月\t|专业    |\n");
        geshi;
        printf("|%d\t|%4s\t|%3d\t|%4s\t|%4s\t|%3d\t|%6d-%02d\t|%-8s|\n", MM);
        geshi;

resecret:
        printf("\t\t\t0.不做修改\n");
        printf("\t\t\t1.修改学生学号\n");
        printf("\t\t\t2.修改学生姓名\n");
        printf("\t\t\t3.修改学生性别\n");
        printf("\t\t\t4.修改学生民族\n");
        printf("\t\t\t5.修改学生年龄\n");
        printf("\t\t\t6.修改学生班级\n");
        printf("\t\t\t7.修改出生年月\n");
        printf("\t\t\t8.修改学生专业\n");
        printf("\t\t\t9.修改所有数据\n");
        printf("\t\t\t请选择您要修改的学生数据：");

        scanf(" %c", &secret);
        switch ( secret - '0' )
        {
        case 0:
            return ;
        case 1:
            printf("请输入修改后的该学生的学号:\n");
            scanf ("%d", &student[i].number);//学号
            break;
        case 2:
            printf("请输入修改后该生名字:\n");
            scanf ("%s", student[i].name);//名字
            break;
        case 3:
            printf("请输入修改后该生性别:\n");
            scanf ("%s", student[i].sex);//性别
            break;
        case 4:
            printf("请输入修改后该生所属的民族:\n");
            scanf ("%s", student[i].minzu);//性别
            break;
        case 5:
            printf("请输入修改后该生年龄:\n");
            scanf ("%d", &student[i].age);//年龄
            break;
        case 6:
            printf("请输入修改后该生所在的班级:\n");
            scanf("%d", &student[i].banji);
            break;
        case 7:
            printf("请输入修改后该生出生年月（以空格隔开）:\n");
            scanf ("%d %d", &student[i].nian, &student[i].yue);//出生年月
            break;
        case 8:
            printf("请输入修改后该生所在的专业:\n");
            scanf ("%s", student[i].zhuanye);//专业
            break;
        case 9:
            printf("请输入修改后的该学生的学号:\n");
            scanf ("%d", &student[i].number);//学号
            printf("请输入修改后该生名字:\n");
            scanf ("%s", student[i].name);//名字
            printf("请输入修改后该生性别:\n");
            scanf ("%s", student[i].sex);//性别
            printf("请输入修改后该生所属的民族:\n");
            scanf ("%s", student[i].minzu);//性别
            printf("请输入修改后该生年龄:\n");
            scanf ("%d", &student[i].age);//年龄
            printf("请输入修改后该生所在的班级:\n");
            scanf("%d", &student[i].banji);
            printf("请输入修改后该生出生年月（以空格隔开）:\n");
            scanf ("%d %d", &student[i].nian, &student[i].yue);//出生年月
            printf("请输入修改后该生所在的专业:\n");
            scanf ("%s", student[i].zhuanye);//专业
            break;
        default :
            printf("错误的操作选项!\n");
            goto resecret;
        }

        printf("\n\n修改成功！\n\n");
        printf("修改后该生的数据如下:\n");
        geshi;
        printf("|学号\t|姓名\t|班级\t|民族\t|性别\t|年龄\t|出生年月\t|专业    |\n");
        geshi;
        printf("|%d\t|%4s\t|%3d\t|%4s\t|%4s\t|%3d\t|%6d-%02d\t|%-8s|\n\n", MM);
        geshi;
    }
    else
        printf("\n对不起，您没有存入这个学生号！\n");
}
void chazhao(void)//函数：查找一个学生的信息
{
    int i, num, flage = 0;

    printf("\n请输入您要查找的学生号：\n");
    scanf("%d", &num);
    for (i = 0; i < len; i++)
        if (student[i].number == num)
        {
            flage = 1;
            break;
        }
    if (flage)
    {
        printf("\n您查找的学生数据为：\n");
        geshi;
        printf("|学号\t|姓名\t|班级\t|民族\t|性别\t|年龄\t|出生年月\t|专业    |\n");
        geshi;
        printf("|%d\t|%4s\t|%3d\t|%4s\t|%4s\t|%3d\t|%6d-%02d\t|%-8s|\n", MM);
        geshi;
    }
    else
        printf("\n对不起，您没有存入过这个学生号！\n");
}
void shanchu(void)//函数：删除指定学生的信息
{
    int i, num, flage = 0;
    char c;

    shuchu();

    printf("\n请输入您要删除的学生的学号:\n");
    scanf("%d", &num);
    for (i = 0; i < len; i++)
        if (student[i].number == num)
        {
            flage = 1;
            printf("\n您要删除的学生信息如下：\n");
            geshi;
            printf("|学号\t|姓名\t|班级\t|民族\t|性别\t|年龄\t|出生年月\t|专业    |\n");
            geshi;
            printf("|%d\t|%4s\t|%3d\t|%4s\t|%4s\t|%3d\t|%6d-%02d\t|%-8s|\n", MM);
            geshi;
            break;
        }
    printf ("是否确认删除(Y/N):\n");
    scanf(" %c", &c);
    if (flage)
    {
        if (c == 'y' || c == 'Y')
        {
            for ( ; i < len; i++)
                student[i] = student[i+1];
            printf("删除成功！\n");
            len--;
            printf("\n删除之后的学生数据如下:\n");
            shuchu();
        }
        else
            printf("删除失败!\n");
    }
    else
        printf("\n没有您输入的学生的信息！\n");
}
void shuchu(void)//函数：输出学生信息
{
    int i;

    geshi;
    printf("|学号\t|姓名\t|班级\t|民族\t|性别\t|年龄\t|出生年月\t|专业    |\n");
    geshi;
    for (i = 0; i < len; i++)
    {
        printf("|%d\t|%4s\t|%3d\t|%4s\t|%4s\t|%3d\t|%6d-%02d\t|%-8s|\n", MM);
        geshi;
    }

    return ;
}
void charu(void)
{
    int i;

    printf("\n请输入要追加的学生的学号:\n");
b:
    scanf ("%d", &student[len].number);//学号
    for (i = 0; i < len; i++)
        if (student[i].number == student[len].number)
        {
            printf("\n您输入的学号已存在！请重新输入！\n");
            goto b;
        }
    printf("\n请输入要追加的学生的名字:\n");
    scanf ("%s", student[i].name);//名字
    printf("请输入要追加的学生的性别:\n");
    scanf ("%s", student[i].sex);//性别
    printf("请输入要追加的学生的所属的民族:\n");
    scanf ("%s", student[i].minzu);//民族
    printf("请输入要追加的学生的所在的班级(本模块只支持数字输入):\n");
    scanf("%d", &student[i].banji);//班级
    printf("请输入要追加的学生的年龄:\n");
    scanf ("%d", &student[i].age);//年龄
    printf("请输入要追加的学生的出生年月（以空格隔开）:\n");
    scanf ("%d %d", &student[i].nian, &student[i].yue);//出生年月
    printf("请输入要追加的学生所在的专业:\n");
    scanf ("%s", student[i].zhuanye);//专业

    printf("您要追加的学生信息如下:\n");
    geshi;
    printf("|学号\t|姓名\t|班级\t|民族\t|性别\t|年龄\t|出生年月\t|专业    |\n");
    geshi;
    printf("|%d\t|%4s\t|%3d\t|%4s\t|%4s\t|%3d\t|%6d-%02d\t|%-8s|\n", MM);
    geshi;

    printf("追加后的学生数据表如下:\n");
    len++;
    shuchu();
}
void baocun1(void)
{
    int i;
    FILE * fq;

    if ((fq = fopen("学生证管理系统.txt", "w+")) == NULL)
    {
        printf("无效文件路径!\n");
        getch();
        exit(1);
    }
    fprintf(fq, "%s", "|————————————————————————————————————|\n");
    fprintf(fq, "%s", "|学号\t|姓名\t|班级\t|民族\t|性别\t|年龄\t|出生年月\t|专业    |\n");
    fprintf(fq, "%s", "|————————————————————————————————————|\n");

    for (i = 0; i < len; i++)
    {
        fprintf(fq, "|%d\t|%4s\t|%3d\t|%4s\t|%4s\t|%3d\t|%6d-%02d\t|%-8s|\n", MM);
        fprintf(fq, "%s", "|————————————————————————————————————|\n");
    }

    printf("\n保存成功！\n");
    fclose(fq);

    return ;
}
void baocun2(void)
{
    int i;
    FILE * fq;

    if ((fq = fopen("文件.txt", "w+")) == NULL)
    {
        printf("无效文件路径!\n");
        getch();
        exit(1);
    }
    fprintf(fq, "%s", "学号\t姓名\t班级\t民族\t性别\t年龄\t出生年月\t专业\n");

    for (i = 0; i < len; i++)
        fprintf(fq, "%d\t%s\t%d\t%s\t%s\t%d\t%d-%d\t\t%s\n", MM);

    fclose(fq);

    return ;
}
int diaoyong(void)
{
    FILE * fq;
    char str[1000];
    if ((fq = fopen("文件.txt", "r+")) == NULL)
    {
        printf("无效文件路径!\n");
        getch();
        exit(1);
    }
    fscanf(fq, "学号\t姓名\t班级\t民族\t性别\t年龄\t出生年月\t专业\n", str);

    while (0 == feof(fq))
    {
        fscanf(fq, "%d\t%s\t%d\t%s\t%s\t%d\t%d-%d\t%s\n", NN);
        len++;
    }
    printf("\n\n\n调用成功！\n\n");
    printf("学生数据如下：\n\n");
    shuchu();
    fclose(fq);
    return ;
}
void print()
{
    printf("      *****************************************************************\n") ;
    printf("      *****************************************************************\n") ;
    printf("      *                          欢迎进入                             *\n");
    printf("      *                                                               *\n");
    printf("      *                       学生证管理系统 !                        *\n");
    printf("      *                                                               *\n");
    printf("      *****************************************************************\n") ;
    printf("      *****************************************************************\n") ;
    printf("\t\t\t1. 登录\n");
    printf("\t\t\t2. 注册\n");
    printf("\t\t\t3. 退出\n");
    printf("\t\t\t\n\n请选择操作方式:");
    return ;
}
int main(void)
{
    char flage;
    int ti = 0;

type:
    print() ;

    srand((unsigned int )time(NULL)) ;//生成随机数种子
    int i, t, x = 0, tm = 0, z = 0;
    char num[MAX][10], sum[MAX][10];
    int choice;
    int f = 1;

    scanf("%d", &choice);
    char str[5] , arr[5] , name[7] , mima[7] , mo[7], ss[7];
    if (choice == 1)
    {
        FILE * fq = fopen("账户密码系统.txt", "r+");
        while (0 == feof(fq))
        {
            fscanf(fq, "%s %s\n", num[tm], sum[tm]);
            tm++;
        }
        while ( 1 )
        {
            printf("请输入您的账户:");
            scanf("%s",name) ;
            getchar() ;
            for (z = 0; z < tm; z++)
                if (strcmp(name,num[z]) == 0)
                {
                    printf("\n\n\t输入正确!\n\n") ;
                    f = 0;
                    break ;
                }
            if ( f )
            {
                printf("您输入的账号名不存在,请重新选择!\n");
                system("pause");
                system("cls");
                goto type;
            }
            break;
        }
        while ( 1 )
        {
re:
            printf("\t\t注意！您最多只能输入6次密码\n\t\t超过6次程序将会自动结束.\n\n");
            printf("\t\t当前输入次数：第%d次\n\n", x+1);
            x++;
            if (x == 6)
            {
                printf("密码多次错误，本程序自动终止!\n");
                getch();
                exit(1);
            }
            printf("      请输入密码: ") ;
            for (i = 0 ; i < 7; i ++)
            {
                mima[i] = getch() ;
                if (mima[i] == '\b')
                {
                    mo[i-1] = '\0' ;
                    i -= 2 ;
                    system("cls");
                    print();
                    printf("\n\n\t输入正确!\n\n");
                    printf("      请输入密码: ");
                    printf("%s",mo) ;
                }
                else
                {
                    if (mima[i] == '\r')
                        break;
                    mo[i] = '*' ;
                    mo[i+1] = '\0' ;
                    printf("*");
                }

            }
            mima[i] = '\0' ;
            if (strcmp(mima,sum[z]) == 0)
                break;
            else
            {
                puts("");
                printf("您输入的密码错误,请重新输入!\n") ;
                system("pause");
                system("cls");
                goto re;
            }
        }

        t = rand() % 10000 ;
        puts("");
        printf("验证码 :  ") ;
        printf("%04d\n",t);
        sprintf(str,"%04d",t) ;
        printf("请输入验证码:") ;
        scanf("%s",arr) ;
        if (strcmp(str,arr) == 0)
            system("cls");
    }
    else if (2 == choice)
    {
        FILE * fq = fopen("账户密码系统.txt", "a+");

        printf("请创建账户:");
        scanf("%s", name);
        printf("请设置密码:");
        scanf("%s", mima);
        printf("请确认密码:");
        scanf("%s", ss);

        if ( strcmp (ss, mima) )
        {
            printf("前后两次输入的密码不一致！\n");
            printf("请重新选择!\n");
            system("pause");
            system("cls");
            goto type;
        }

        fprintf(fq, "%s %s\n", name, mima);
        printf("创建成功！\n");
        fclose (fq);
        goto type;
    }
    else
        goto end;
    system("cls");


strat:
    printf("\n\n                \t\t欢迎使用学生证管理系统\n\n");
    printf("        \t\t※※※※※※※※※※※※※※※※※\n");
    printf("        \t\t※\t学 生 管 理 系 统       ※\n");
    printf("        \t\t※\t1. 输入学生证数据       ※\n");
    printf("        \t\t※\t2. 修改学生证数据       ※\n");
    printf("        \t\t※\t3. 查找学生证成绩       ※\n");
    printf("        \t\t※\t4. 排列学生证数据       ※\n");
    printf("        \t\t※\t5. 删除学生证资料       ※\n");
    printf("        \t\t※\t6. 打印学生证信息       ※\n");
    printf("        \t\t※\t7. 追加学生证数据       ※\n");
    printf("        \t\t※\t8. 保存学生证数据       ※\n");
    printf("        \t\t※\t9. 调用学生证数据       ※\n");
    printf("        \t\t※\t0. 结束程序             ※\n");
    printf("        \t\t※※※※※※※※※※※※※※※※※\n");
    printf("        \n\n\t\t请选择操作方式:");
choice:
    scanf(" %c", &flage);
    if (flage < '0' || flage > '9')
    {
        printf("您的输入有误！请重新输入数字(0~9):\n");
        goto  choice;
    }

    if (0 == time && flage != '1' && flage != '9' && flage != '0')
    {
        printf("该文件目前为空，请选择输入(1)或者调用(9)\n");
        goto  choice;
    }
    switch (flage - '0')
    {
    case 1:
        system("cls");
        ti = 1;
        printf("请输入学生人数:");
        scanf("%d", &len);//输入学生人数
        shuru();
        system("pause");
        goto strat;
    case 2:
        system("cls");
        xiugai();
        system("pause");
        goto strat;
    case 3:
        system("cls");
        chazhao();
        system("pause");
        goto strat;
    case 4:
        system("cls");
        paixu();
        system("pause");
        goto strat;
    case 5:
        system("cls");
        shanchu();
        system("pause");
        goto strat;
    case 6:
        system("cls");
        shuchu();
        system("pause");
        goto strat;
    case 7:
        system("cls");
        charu();
        system("pause");
        goto strat;
    case 8:
        system("cls");
        baocun1();
        baocun2();
        system("pause");
        goto strat;
    case 9:
        system("cls");
        ti = 1;
        diaoyong();
        system("pause");
        goto strat;
    case 0:
        goto end;
    }
end:
    system("cls");
    printf("\n\n        \t\t\n\n");
    printf("        \t\t※※※※※※※※※※※※※※※※※\n");
    printf("        \t\t※\t    本程序使用完成      ※\n");
    printf("        \t\t※\t     欢迎再次使用       ※\n");
    printf("        \t\t※\t                        ※\n");
    printf("        \t\t※\t指导老师:               ※\n");
    printf("        \t\t※\t         张延亮老师     ※\n");
    printf("        \t\t※\t制 作 人:               ※\n");
    printf("        \t\t※\t         何鑫奇         ※\n");
    printf("        \t\t※\t         郭界全         ※\n");
    printf("        \t\t※\t         谢振宇         ※\n");
    printf("        \t\t※\t         邱  铃         ※\n");
    printf("        \t\t※\t         王  倩         ※\n");
    printf("        \t\t※\t                        ※\n");
    printf("        \t\t※※※※※※※※※※※※※※※※※\n");

    return 0;
}
