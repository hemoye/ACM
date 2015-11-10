#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/********����ѧ���ṹ��********/
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
int amount=0;//��¼ѧ������
/*****************************/
/***********��ʼ��ѧ����*************/
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
/**************����ѧ�����ݱ�*********************/
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
            printf("����ʧ�ܣ�");
            return 0;
        }
        printf("������ѧ��(����0�˻���һ��):");
        scanf("%d",&s->number);
        if(s->number==0)
            goto endp;
        if(n==s->number)
        {
            printf("����ѧ���Ѵ���!\n");
            goto end;
        }
        while(s->number<0)
        {
            getchar();
            printf("\nѧ�Ų���ΪС����!");
            printf("\n������ѧ��,����0�˻���һ��:");
            scanf("%d",&s->number);
        }
        printf("����������:");
        scanf("%s",s->name);
        printf("�������Ա�m/w:");
        scanf("%s",s->sex);
        printf("���������ĳɼ�:");
        scanf("%d",&s->Chinese);
        while(s->Chinese>100||s->Chinese<0)
        {
            getchar();
            printf("���������ĳɼ�:");
            scanf("%d",&s->Chinese);
        }
        printf("��������ѧ�ɼ�:");
        scanf("%d",&s->Match);
        while(s->Match>100||s->Match<0)
        {
            getchar();
            printf("��������ѧ�ɼ�:");
            scanf("%d",&s->Match);
        }
        printf("������Ӣ��ɼ�:");
        scanf("%d",&s->English);
        while(s->English>100||s->English<0)
        {
            getchar();
            printf("������Ӣ��ɼ�:");
            scanf("%d",&s->English);
        }
        s->average=(s->Chinese+s->English+s->Match)/3;
        n=s->number;
        s->next=Q->next;
        Q->next=s;
        amount++;
end:
        printf("�Ƿ������������:1/0\n");
        scanf("%d",&flag);

    }
endp:
    printf("������ϣ�\n");
    printf("������%d��ѧ��",amount);
    return 1;
}
/******************************************/
/*********************����ѧ�����ݣ���ѧ��Ϊǰ��****************/
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
/**************************�޸�ѧ������**************************/
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
            printf("\n�޸ĳɼ���Ŀ��1.����  2.Ӣ��  3.��ѧ:");
            scanf("%d",&flag);
            if(flag==1)
            {
                getchar();
                printf("\n���������ĳɼ�:");
                scanf("%d",&q->Chinese);
                while(q->Chinese>100||q->Chinese<0)
                {
                    getchar();
                    printf("\n���������ĳɼ�:");
                    scanf("%d",&q->Chinese);
                }
            }
            else if(flag==2)
            {

                getchar();
                printf("\n��������ѧ�ɼ�:");
                scanf("%d",&q->Match);
                while(q->Match>100||q->Match<0)
                {
                    getchar();
                    printf("\n������������ѧ�ɼ�:");
                    scanf("%d",&q->Match);
                }
            }
            else if(flag==3)
            {
                getchar();
                printf("\n������Ӣ��ɼ�:");
                scanf("%d",&q->English);
                while(q->English>100||q->English<0)
                {
                    printf("\n������Ӣ��ɼ�:");
                    scanf("%d",&q->English);
                }
            }
            q->average=(q->Chinese+q->English+q->Match)/3;
            printf("\n�Ƿ�����޸�����:1/0\n");
            scanf("%d",&n);
        }

        return 1;
    }

    return 0;
}
/******************************************************/
/************************����ѧ������***********************/
Student *Sort(Student *Q,int course)
{

    Student *p,*q,*t;
    int number,Chinese,English,Match,score;
    char name[10],sex[2];
    if(Q->next==NULL)
    {
        printf("û�й���ѧ����");
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
    printf("�������ļ�·��:");
    scanf("%s",open);
    if((fp=fopen(open,"w+"))==NULL)
    {
        printf("��ʧ��!");
        return 0;
    }
    fprintf(fp,"|ѧ��\t|����\t|�Ա�\t|����\t|Ӣ��\t|��ѧ\t|����\t|\n");

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
/************************���ѧ���ɼ�*******************************************/
void print(Student *Q)
{
    Student *p;
    p=Q;
    if(Q->next==NULL)
        printf("û��ѧ������!");
    else
    {
        printf("���Ϊ��\n");
        while(p->next!=NULL)
        {
            p=p->next;

            printf("|ѧ��\t|����\t|�Ա�\t|����\t|Ӣ��\t|��ѧ\t|����\t|\n");
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
    printf("����������ļ���·��:");
    scanf("%s",FileName[20]);
    if((fp=fopen(FileName,"r+"))!=NULL)
    {
        fscanf(fp,"|ѧ��\t|����\t|�Ա�\t|����\t|Ӣ��\t|��ѧ\t|����\t|\n");
        printf("|ѧ��\t|����\t|�Ա�\t|����\t|Ӣ��\t|��ѧ\t|����\t|\n");
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
        printf("����ʧ�ܣ�");
    fclose(fp);

}
/***************************************�˵�����********************************/
void Menu()
{
    int flag,n,sure,course;
    Student *Q,*p,*L;
    n=0;
    Q=InitStudent();
begin:
    printf("\n\t\t\t   ѧ������ϵͳ(�����뺺��)\n");
    printf("|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n");
    printf("|1����ѧ������\t\t\t2�޸�ѧ������\t\t\t3����ѧ���ɼ�|\n");
    printf("|4����ѧ������\t\t\t5����ѧ���ɼ�\t\t\t6�����ļ�����|\n");
    printf("|7��ʾѧ������\t\t\t0��������   \t\t\t             |\n");
    printf("|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n");
    printf("\n������ʽ:");
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
            printf("���������ѧ��ѧ��:");
            scanf("%d",&n);
        }
        sure=ModifStudent(Q,n);
        if(sure==1)
            printf("�޸ĳɹ�\n");
        else
            printf("�޸�ʧ��\n");
        n=0;
        goto begin;
    case 3:
        while(n==0)
        {
            printf("���������ѧ��ѧ��:");
            scanf("%d",&n);
        }
        p=FindStudent(Q,n);
        if(p!=NULL)
        {
            printf("\n��ѯ���Ϊ��\n");
            printf("|ѧ��\t|����\t|�Ա�\t|����\t|Ӣ��\t|��ѧ\t|����\t|\n");
            printf("|%d\t|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n",p->number,p->name,p->sex,p->Chinese,p->English,p->Match,p->average);
        }
        else
            printf("����ʧ��\n");
        n=0;
        goto begin;


    case 4:
        printf("�������������(����0������һ��)\n1.���� 2.Ӣ�� 3.��ѧ:");
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
    printf("\n\t\t\t\t    ѧ������ϵͳ\n");
    printf("|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n");
    printf("|1����ѧ������\t\t\t2�޸�ѧ������\t\t\t3����ѧ���ɼ�|\n");
    printf("|0�˳�����\n");
    printf("|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n");
}
/************************************����*************************************/
/*****************************************************/
void main()//������
{
    Menu();
}
