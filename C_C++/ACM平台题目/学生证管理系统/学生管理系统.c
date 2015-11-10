#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/********定义学生结构体********/
typedef struct Link
{
    int number;
    char name[10];
    char sex[4];
    int  Chinese;
    int  English;
    int  Match;
    float  average;
    struct Link *next;
} Student;
int amount=0;//记录学生个数
/*****************************/
/***********初始化学生表*************/
Student *InitStudent()
{
    Student *Q;
    Q=(Student*)malloc(sizeof(Student));
    if(Q!=NULL)
    {
        Q->next=NULL;
        return Q;
    }
    else
        return NULL;
}
/***********************************/
/**************创建学生数据表*********************/
int CreatStudent(Student *Q)
{
    int flag,n;
    Student *s;
    n=0;
    while(flag)
    {
        s=(Student*)malloc(sizeof(Student));
        if(s==NULL)
        {
            printf("创建失败！");
            return 0;
        }
        printf("请输入学号(输入0退回上一步):");
        scanf("%d",&s->number);
        if(s->number==0)
            goto endp;
        if(n==s->number)
        {
            printf("输入学号已存在!\n");
            goto end;
        }
        while(s->number<0)
        {
            getchar();
            printf("\n学号不能为小于零!");
            printf("\n请输入学号,输入0退回上一步:");
            scanf("%d",&s->number);
        }
        printf("请输入姓名:");
        scanf("%s",s->name);
        printf("请输入性别m/w:");
        scanf("%s",s->sex);
        printf("请输入语文成绩:");
        scanf("%d",&s->Chinese);
        while(s->Chinese>100||s->Chinese<0)
        {
            getchar();
            printf("请输入语文成绩:");
            scanf("%d",&s->Chinese);
        }
        printf("请输入数学成绩:");
        scanf("%d",&s->Match);
        while(s->Match>100||s->Match<0)
        {
            getchar();
            printf("请输入数学成绩:");
            scanf("%d",&s->Match);
        }
        printf("请输入英语成绩:");
        scanf("%d",&s->English);
        while(s->English>100||s->English<0)
        {
            getchar();
            printf("请输入英语成绩:");
            scanf("%d",&s->English);
        }
        s->average=(s->Chinese+s->English+s->Match)/3;
        n=s->number;
        s->next=Q->next;
        Q->next=s;
        amount++;
end:
        printf("是否继续输入数据:1/0\n");
        scanf("%d",&flag);

    }
endp:
    printf("创建完毕！\n");
    printf("输入了%d个学生",amount);
    return 1;
}
/******************************************/
/*********************查找学生数据，以学号为前提****************/
Student *FindStudent(Student *Q,int x)
{

    Student *q;
    q=Q->next;
    while(q!=NULL&&q->number!=x)
        q=q->next;
    if(q!=NULL)
        return q;
    else
        return NULL;
}
/******************************************************/
/**************************修改学生数据**************************/
int ModifStudent(Student *Q,int x)
{
    int flag,n;
    Student *q;
    q=Q->next;
    while(q!=NULL&&q->number!=x)
        q=q->next;
    if(q!=NULL)
    {
        while(n)
        {
            printf("\n修改成绩科目：1.语文  2.英语  3.数学:");
            scanf("%d",&flag);
            if(flag==1)
            {
                getchar();
                printf("\n请输入语文成绩:");
                scanf("%d",&q->Chinese);
                while(q->Chinese>100||q->Chinese<0)
                {
                    getchar();
                    printf("\n请输入语文成绩:");
                    scanf("%d",&q->Chinese);
                }
            }
            else if(flag==2)
            {

                getchar();
                printf("\n请输入数学成绩:");
                scanf("%d",&q->Match);
                while(q->Match>100||q->Match<0)
                {
                    getchar();
                    printf("\n请重新输入数学成绩:");
                    scanf("%d",&q->Match);
                }
            }
            else if(flag==3)
            {
                getchar();
                printf("\n请输入英语成绩:");
                scanf("%d",&q->English);
                while(q->English>100||q->English<0)
                {
                    printf("\n请重新英语成绩:");
                    scanf("%d",&q->English);
                }
            }
            q->average=(q->Chinese+q->English+q->Match)/3;
            printf("\n是否继续修改数据:1/0\n");
            scanf("%d",&n);
        }

        return 1;
    }

    return 0;
}
/******************************************************/
/************************排列学生数据***********************/
Student *Sort(Student *Q,int course)
{

    Student *p,*q,*t;
    int number,Chinese,English,Match,score;
    char name[10],sex[2];
    if(Q->next==NULL)
    {
        printf("没有构造学生表！");
        return NULL;
    }
    switch(course)
    {
    case 1:
        for(p=Q->next; p; p=p->next)
        {
            t=p;
            for(q=Q->next; q; q=q->next)
            {
                if(t->Chinese>=q->Chinese)
                {
                    number=t->number;
                    Chinese=t->Chinese;
                    English=t->English;
                    Match=t->Match;
                    score=t->average;
                    t->number=q->number;
                    t->Chinese=q->Chinese;
                    t->English=q->English;
                    t->Match=q->Match;
                    t->average=q->average;
                    q->number=number;
                    q->Chinese=Chinese;
                    q->English=English;
                    q->Match=Match;
                    q->average=score;
                    strcpy(name,t->name);
                    strcpy(sex,t->sex);
                    strcpy(t->name,q->name);
                    strcpy(t->sex,q->sex);
                    strcpy(q->name,name);
                    strcpy(q->sex,sex);
                    t=q;
                }
            }
        }
        break;
    case 2:
        for(p=Q->next; p; p=p->next)
        {
            t=p;
            for(q=Q->next; q; q=q->next)
            {
                if(t->English>=q->English)
                {
                    number=t->number;
                    Chinese=t->Chinese;
                    English=t->English;
                    Match=t->Match;
                    score=t->average;
                    t->number=q->number;
                    t->Chinese=q->Chinese;
                    t->English=q->English;
                    t->Match=q->Match;
                    t->average=q->average;
                    q->number=number;
                    q->Chinese=Chinese;
                    q->English=English;
                    q->Match=Match;
                    q->average=score;
                    strcpy(name,t->name);
                    strcpy(sex,t->sex);
                    strcpy(t->name,q->name);
                    strcpy(t->sex,q->sex);
                    strcpy(q->name,name);
                    strcpy(q->sex,sex);
                    t=q;
                }
            }
        }
        break;
    case 3:
        for(p=Q->next; p; p=p->next)
        {
            t=p;
            for(q=Q->next; q; q=q->next)
            {
                if(t->Match>=q->Match)
                {
                    number=t->number;
                    Chinese=t->Chinese;
                    English=t->English;
                    Match=t->Match;
                    score=t->average;
                    t->number=q->number;
                    t->Chinese=q->Chinese;
                    t->English=q->English;
                    t->Match=q->Match;
                    t->average=q->average;
                    q->number=number;
                    q->Chinese=Chinese;
                    q->English=English;
                    q->Match=Match;
                    q->average=score;
                    strcpy(name,t->name);
                    strcpy(sex,t->sex);
                    strcpy(t->name,q->name);
                    strcpy(t->sex,q->sex);
                    strcpy(q->name,name);
                    strcpy(q->sex,sex);
                    t=q;
                }
            }
        }
        break;



    }
    return Q;

}
int SaveStudent(Student *Q)
{
    int i=0;
    Student *p;
    FILE *fp;
    char open[20];
    p=Q->next;
    printf("请输入文件路径:");
    scanf("%s",open);
    if((fp=fopen(open,"w+"))==NULL)
    {
        printf("打开失败!");
        return 0;
    }
    fprintf(fp,"|学号\t|姓名\t|性别\t|语文\t|英语\t|数学\t|均分\t|\n");

    while(p!=NULL&&i<amount)
    {
        i++;
        fwrite(p,sizeof(Student),1,fp);
        p=p->next;
        //fprintf(fp,"|%d\t|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n",p->number,p->name,p->sex,p->Chinese,p->English,p->Match,p->average);
    }
    fclose(fp);
    return 1;
}

/******************************************************************/
/************************输出学生成绩*******************************************/
void print(Student *Q)
{
    Student *p;
    p=Q;
    if(Q->next==NULL)
        printf("没有学生资料!");
    else
    {
        printf("结果为：\n");
        while(p->next!=NULL)
        {
            p=p->next;

            printf("|学号\t|姓名\t|性别\t|语文\t|英语\t|数学\t|均分\t|\n");
            printf("|%d\t|%s\t|%s\t|%d\t|%d\t|%d\t|%0.2f\t|\n",p->number,p->name,p->sex,p->Chinese,p->English,p->Match,p->average);
        }
    }

}
/********************************************************************************/
/********************************************************************************/
void LoadStudent()
{
    int flag=1;
    char FileName[20];
    Student *p;
    FILE *fp;
    printf("请输入调出文件的路径:");
    scanf("%s",FileName[20]);
    if((fp=fopen(FileName,"r+"))!=NULL)
    {
        fscanf(fp,"|学号\t|姓名\t|性别\t|语文\t|英语\t|数学\t|均分\t|\n");
        printf("|学号\t|姓名\t|性别\t|语文\t|英语\t|数学\t|均分\t|\n");
        while(flag)
        {
            p=(Student*)malloc(sizeof(Student));
            fscanf(fp,"%d%s%s%d%d%d%d",&p->number,p->name,p->sex,&p->Chinese,&p->English,&p->Match,&p->average);
            if(p->number==NULL)
                flag=0;
            else
            {
                printf("|%d\t|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n",p->number,p->name,p->sex,p->Chinese,p->English,p->Match,p->average);
                flag=1;
            }
        }

    }
    else
        printf("调出失败！");
    fclose(fp);

}
/***************************************菜单界面********************************/
void Menu()
{
    int flag,n,sure,course;
    Student *Q,*p,*L;
    n=0;
    Q=InitStudent();
begin:
    printf("\n\t\t\t   学生管理系统(可输入汉字)\n");
    printf("|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n");
    printf("|1输入学生数据\t\t\t2修改学生数据\t\t\t3查找学生成绩|\n");
    printf("|4排列学生数据\t\t\t5保存学生成绩\t\t\t6调出文件资料|\n");
    printf("|7显示学生资料\t\t\t0结束程序   \t\t\t             |\n");
    printf("|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n");
    printf("\n操作方式:");
    scanf("%d",&flag);
    switch(flag)
    {
    case 0:
        goto end;
        break;
    case 1:
        CreatStudent(Q);
        print(Q);
        goto begin;
    case 2:
        while(n==0)
        {
            printf("请输入查找学生学号:");
            scanf("%d",&n);
        }
        sure=ModifStudent(Q,n);
        if(sure==1)
            printf("修改成功\n");
        else
            printf("修改失败\n");
        n=0;
        goto begin;
    case 3:
        while(n==0)
        {
            printf("请输入查找学生学号:");
            scanf("%d",&n);
        }
        p=FindStudent(Q,n);
        if(p!=NULL)
        {
            printf("\n查询结果为：\n");
            printf("|学号\t|姓名\t|性别\t|语文\t|英语\t|数学\t|均分\t|\n");
            printf("|%d\t|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n",p->number,p->name,p->sex,p->Chinese,p->English,p->Match,p->average);
        }
        else
            printf("查找失败\n");
        n=0;
        goto begin;


    case 4:
        printf("请输入排序规则(输入0返回上一步)\n1.语文 2.英语 3.数学:");
        scanf("%d",&course);
        if(course==0)
            goto begin;
        else
        {
            L=Sort(Q,course);
            if(L!=NULL)
                print(L);
        }
        goto begin;
    case 5:
        SaveStudent(Q);
        goto begin;
    case 6:
        LoadStudent();
        goto begin;
    case 7:
        print(Q);
        goto begin;
    }

end:
    printf("\n\t\t\t\t    学生管理系统\n");
    printf("|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n");
    printf("|1输入学生数据\t\t\t2修改学生数据\t\t\t3查找学生成绩|\n");
    printf("|0退出程序\n");
    printf("|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n");
}
/************************************结束*************************************/
/*****************************************************/
void main()//主函数
{
    Menu();
}
