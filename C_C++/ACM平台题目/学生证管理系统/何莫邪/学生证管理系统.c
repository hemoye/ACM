#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 401
#define MM student[i].number, student[i].name, student[i].banji, student[i].minzu, student[i].sex, student[i].age, student[i].nian, student[i].yue, student[i].zhuanye
#define NN &student[len].number,student[len].name,&student[len].banji,student[len].minzu,student[len].sex,&student[len].age,&student[len].nian,&student[len].yue,student[len].zhuanye
#define geshi printf("|������������������������������������������������������������������������|\n")

int len = 0;

struct stud//����ṹ��
{
    int nian;//���������
    int yue;//�������·�
    int age;//���ڴ洢����
    int number;//���ڴ洢ѧ��
    int banji;
    char minzu[31];
    char name[31];//���ڴ洢����
    char sex[31];//�Ա�
    char zhuanye[31];//רҵ
} student[MAX];

void shuru(void)
{
    int i, j, x = 0;
    int num = len;

    for (i = 0; i < num; i++)
    {
a:
        printf("�������%d��ѧ����ѧ��:\n", i + 1);
        scanf ("%d", &student[i].number);//ѧ��
        for (j = 0; j < i; j++)
            if (student[i].number == student[j].number)
            {
                printf("�������ѧ���Ѵ��ڣ����������룡\n");
                goto a;
            }
        printf("�������%d��ѧ��������:\n", i + 1);
        scanf ("%s", student[i].name);//����
        printf("�������%d��ѧ�����Ա�:\n", i + 1);
        scanf ("%s", student[i].sex);//�Ա�
        printf("�������%d��ѧ��������������:\n", i + 1);
        scanf ("%s", student[i].minzu);//����
        printf("�������%d��ѧ�������ڵİ༶(��ģ��ֻ֧����������):\n", i + 1);
        scanf("%d", &student[i].banji);//�༶
        printf("�������%d��ѧ��������:\n", i + 1);
        scanf ("%d", &student[i].age);//����
        printf("�������%d��ѧ���ĳ������£��Կո������:\n", i + 1);
        scanf ("%d %d", &student[i].nian, &student[i].yue);//��������
        printf("�������%d��ѧ�������ڵ�רҵ:\n", i + 1);
        scanf ("%s", student[i].zhuanye);//רҵ
        system("cls");
    }
    shuchu();
}
void paixu(void)
{
    int i, j, flage;
    struct stud temp;

    printf("����������Ҫ������ʽ��\n");
    printf("1.��ѧ��˳���С��������\n");
    printf("2.���������´�С��������\n");
    printf("3.�������С��������\n");
    printf("4.���༶��С��������\n");

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
        printf("\n������Ҫ������ʽ����:\n");
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
        printf("\n������Ҫ������ʽ����:\n");
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
        printf("\n������Ҫ������ʽ����:\n");
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
        printf("\n������Ҫ������ʽ����:\n");
        shuchu();
    }
    else
        printf("\n������֧������ѡ�������ʽ��\n");
}
void xiugai(void)//�������޸�ָ��ѧ������Ϣ
{
    int i, num, flage = 0;
    char secret;

    shuchu();
    printf("\n��������Ҫ�޸ĵ�ѧ����ѧ��:\n\n");
    scanf("%d", &num);

    for (i = 0; i < len; i++)
        if (student[i].number == num)
        {
            flage = 1;
            break;
        }
    if (flage)
    {
        printf("��Ҫ�޸ĵ�ѧ����������:\n\n");
        geshi;
        printf("|ѧ��\t|����\t|�༶\t|����\t|�Ա�\t|����\t|��������\t|רҵ    |\n");
        geshi;
        printf("|%d\t|%4s\t|%3d\t|%4s\t|%4s\t|%3d\t|%6d-%02d\t|%-8s|\n", MM);
        geshi;

resecret:
        printf("\t\t\t0.�����޸�\n");
        printf("\t\t\t1.�޸�ѧ��ѧ��\n");
        printf("\t\t\t2.�޸�ѧ������\n");
        printf("\t\t\t3.�޸�ѧ���Ա�\n");
        printf("\t\t\t4.�޸�ѧ������\n");
        printf("\t\t\t5.�޸�ѧ������\n");
        printf("\t\t\t6.�޸�ѧ���༶\n");
        printf("\t\t\t7.�޸ĳ�������\n");
        printf("\t\t\t8.�޸�ѧ��רҵ\n");
        printf("\t\t\t9.�޸���������\n");
        printf("\t\t\t��ѡ����Ҫ�޸ĵ�ѧ�����ݣ�");

        scanf(" %c", &secret);
        switch ( secret - '0' )
        {
        case 0:
            return ;
        case 1:
            printf("�������޸ĺ�ĸ�ѧ����ѧ��:\n");
            scanf ("%d", &student[i].number);//ѧ��
            break;
        case 2:
            printf("�������޸ĺ��������:\n");
            scanf ("%s", student[i].name);//����
            break;
        case 3:
            printf("�������޸ĺ�����Ա�:\n");
            scanf ("%s", student[i].sex);//�Ա�
            break;
        case 4:
            printf("�������޸ĺ��������������:\n");
            scanf ("%s", student[i].minzu);//�Ա�
            break;
        case 5:
            printf("�������޸ĺ��������:\n");
            scanf ("%d", &student[i].age);//����
            break;
        case 6:
            printf("�������޸ĺ�������ڵİ༶:\n");
            scanf("%d", &student[i].banji);
            break;
        case 7:
            printf("�������޸ĺ�����������£��Կո������:\n");
            scanf ("%d %d", &student[i].nian, &student[i].yue);//��������
            break;
        case 8:
            printf("�������޸ĺ�������ڵ�רҵ:\n");
            scanf ("%s", student[i].zhuanye);//רҵ
            break;
        case 9:
            printf("�������޸ĺ�ĸ�ѧ����ѧ��:\n");
            scanf ("%d", &student[i].number);//ѧ��
            printf("�������޸ĺ��������:\n");
            scanf ("%s", student[i].name);//����
            printf("�������޸ĺ�����Ա�:\n");
            scanf ("%s", student[i].sex);//�Ա�
            printf("�������޸ĺ��������������:\n");
            scanf ("%s", student[i].minzu);//�Ա�
            printf("�������޸ĺ��������:\n");
            scanf ("%d", &student[i].age);//����
            printf("�������޸ĺ�������ڵİ༶:\n");
            scanf("%d", &student[i].banji);
            printf("�������޸ĺ�����������£��Կո������:\n");
            scanf ("%d %d", &student[i].nian, &student[i].yue);//��������
            printf("�������޸ĺ�������ڵ�רҵ:\n");
            scanf ("%s", student[i].zhuanye);//רҵ
            break;
        default :
            printf("����Ĳ���ѡ��!\n");
            goto resecret;
        }

        printf("\n\n�޸ĳɹ���\n\n");
        printf("�޸ĺ��������������:\n");
        geshi;
        printf("|ѧ��\t|����\t|�༶\t|����\t|�Ա�\t|����\t|��������\t|רҵ    |\n");
        geshi;
        printf("|%d\t|%4s\t|%3d\t|%4s\t|%4s\t|%3d\t|%6d-%02d\t|%-8s|\n\n", MM);
        geshi;
    }
    else
        printf("\n�Բ�����û�д������ѧ���ţ�\n");
}
void chazhao(void)//����������һ��ѧ������Ϣ
{
    int i, num, flage = 0;

    printf("\n��������Ҫ���ҵ�ѧ���ţ�\n");
    scanf("%d", &num);
    for (i = 0; i < len; i++)
        if (student[i].number == num)
        {
            flage = 1;
            break;
        }
    if (flage)
    {
        printf("\n�����ҵ�ѧ������Ϊ��\n");
        geshi;
        printf("|ѧ��\t|����\t|�༶\t|����\t|�Ա�\t|����\t|��������\t|רҵ    |\n");
        geshi;
        printf("|%d\t|%4s\t|%3d\t|%4s\t|%4s\t|%3d\t|%6d-%02d\t|%-8s|\n", MM);
        geshi;
    }
    else
        printf("\n�Բ�����û�д�������ѧ���ţ�\n");
}
void shanchu(void)//������ɾ��ָ��ѧ������Ϣ
{
    int i, num, flage = 0;
    char c;

    shuchu();

    printf("\n��������Ҫɾ����ѧ����ѧ��:\n");
    scanf("%d", &num);
    for (i = 0; i < len; i++)
        if (student[i].number == num)
        {
            flage = 1;
            printf("\n��Ҫɾ����ѧ����Ϣ���£�\n");
            geshi;
            printf("|ѧ��\t|����\t|�༶\t|����\t|�Ա�\t|����\t|��������\t|רҵ    |\n");
            geshi;
            printf("|%d\t|%4s\t|%3d\t|%4s\t|%4s\t|%3d\t|%6d-%02d\t|%-8s|\n", MM);
            geshi;
            break;
        }
    printf ("�Ƿ�ȷ��ɾ��(Y/N):\n");
    scanf(" %c", &c);
    if (flage)
    {
        if (c == 'y' || c == 'Y')
        {
            for ( ; i < len; i++)
                student[i] = student[i+1];
            printf("ɾ���ɹ���\n");
            len--;
            printf("\nɾ��֮���ѧ����������:\n");
            shuchu();
        }
        else
            printf("ɾ��ʧ��!\n");
    }
    else
        printf("\nû���������ѧ������Ϣ��\n");
}
void shuchu(void)//���������ѧ����Ϣ
{
    int i;

    geshi;
    printf("|ѧ��\t|����\t|�༶\t|����\t|�Ա�\t|����\t|��������\t|רҵ    |\n");
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

    printf("\n������Ҫ׷�ӵ�ѧ����ѧ��:\n");
b:
    scanf ("%d", &student[len].number);//ѧ��
    for (i = 0; i < len; i++)
        if (student[i].number == student[len].number)
        {
            printf("\n�������ѧ���Ѵ��ڣ����������룡\n");
            goto b;
        }
    printf("\n������Ҫ׷�ӵ�ѧ��������:\n");
    scanf ("%s", student[i].name);//����
    printf("������Ҫ׷�ӵ�ѧ�����Ա�:\n");
    scanf ("%s", student[i].sex);//�Ա�
    printf("������Ҫ׷�ӵ�ѧ��������������:\n");
    scanf ("%s", student[i].minzu);//����
    printf("������Ҫ׷�ӵ�ѧ�������ڵİ༶(��ģ��ֻ֧����������):\n");
    scanf("%d", &student[i].banji);//�༶
    printf("������Ҫ׷�ӵ�ѧ��������:\n");
    scanf ("%d", &student[i].age);//����
    printf("������Ҫ׷�ӵ�ѧ���ĳ������£��Կո������:\n");
    scanf ("%d %d", &student[i].nian, &student[i].yue);//��������
    printf("������Ҫ׷�ӵ�ѧ�����ڵ�רҵ:\n");
    scanf ("%s", student[i].zhuanye);//רҵ

    printf("��Ҫ׷�ӵ�ѧ����Ϣ����:\n");
    geshi;
    printf("|ѧ��\t|����\t|�༶\t|����\t|�Ա�\t|����\t|��������\t|רҵ    |\n");
    geshi;
    printf("|%d\t|%4s\t|%3d\t|%4s\t|%4s\t|%3d\t|%6d-%02d\t|%-8s|\n", MM);
    geshi;

    printf("׷�Ӻ��ѧ�����ݱ�����:\n");
    len++;
    shuchu();
}
void baocun1(void)
{
    int i;
    FILE * fq;

    if ((fq = fopen("ѧ��֤����ϵͳ.txt", "w+")) == NULL)
    {
        printf("��Ч�ļ�·��!\n");
        getch();
        exit(1);
    }
    fprintf(fq, "%s", "|������������������������������������������������������������������������|\n");
    fprintf(fq, "%s", "|ѧ��\t|����\t|�༶\t|����\t|�Ա�\t|����\t|��������\t|רҵ    |\n");
    fprintf(fq, "%s", "|������������������������������������������������������������������������|\n");

    for (i = 0; i < len; i++)
    {
        fprintf(fq, "|%d\t|%4s\t|%3d\t|%4s\t|%4s\t|%3d\t|%6d-%02d\t|%-8s|\n", MM);
        fprintf(fq, "%s", "|������������������������������������������������������������������������|\n");
    }

    printf("\n����ɹ���\n");
    fclose(fq);

    return ;
}
void baocun2(void)
{
    int i;
    FILE * fq;

    if ((fq = fopen("�ļ�.txt", "w+")) == NULL)
    {
        printf("��Ч�ļ�·��!\n");
        getch();
        exit(1);
    }
    fprintf(fq, "%s", "ѧ��\t����\t�༶\t����\t�Ա�\t����\t��������\tרҵ\n");

    for (i = 0; i < len; i++)
        fprintf(fq, "%d\t%s\t%d\t%s\t%s\t%d\t%d-%d\t\t%s\n", MM);

    fclose(fq);

    return ;
}
int diaoyong(void)
{
    FILE * fq;
    char str[1000];
    if ((fq = fopen("�ļ�.txt", "r+")) == NULL)
    {
        printf("��Ч�ļ�·��!\n");
        getch();
        exit(1);
    }
    fscanf(fq, "ѧ��\t����\t�༶\t����\t�Ա�\t����\t��������\tרҵ\n", str);

    while (0 == feof(fq))
    {
        fscanf(fq, "%d\t%s\t%d\t%s\t%s\t%d\t%d-%d\t%s\n", NN);
        len++;
    }
    printf("\n\n\n���óɹ���\n\n");
    printf("ѧ���������£�\n\n");
    shuchu();
    fclose(fq);
    return ;
}
void print()
{
    printf("      *****************************************************************\n") ;
    printf("      *****************************************************************\n") ;
    printf("      *                          ��ӭ����                             *\n");
    printf("      *                                                               *\n");
    printf("      *                       ѧ��֤����ϵͳ !                        *\n");
    printf("      *                                                               *\n");
    printf("      *****************************************************************\n") ;
    printf("      *****************************************************************\n") ;
    printf("\t\t\t1. ��¼\n");
    printf("\t\t\t2. ע��\n");
    printf("\t\t\t3. �˳�\n");
    printf("\t\t\t\n\n��ѡ�������ʽ:");
    return ;
}
int main(void)
{
    char flage;
    int ti = 0;

type:
    print() ;

    srand((unsigned int )time(NULL)) ;//�������������
    int i, t, x = 0, tm = 0, z = 0;
    char num[MAX][10], sum[MAX][10];
    int choice;
    int f = 1;

    scanf("%d", &choice);
    char str[5] , arr[5] , name[7] , mima[7] , mo[7], ss[7];
    if (choice == 1)
    {
        FILE * fq = fopen("�˻�����ϵͳ.txt", "r+");
        while (0 == feof(fq))
        {
            fscanf(fq, "%s %s\n", num[tm], sum[tm]);
            tm++;
        }
        while ( 1 )
        {
            printf("�����������˻�:");
            scanf("%s",name) ;
            getchar() ;
            for (z = 0; z < tm; z++)
                if (strcmp(name,num[z]) == 0)
                {
                    printf("\n\n\t������ȷ!\n\n") ;
                    f = 0;
                    break ;
                }
            if ( f )
            {
                printf("��������˺���������,������ѡ��!\n");
                system("pause");
                system("cls");
                goto type;
            }
            break;
        }
        while ( 1 )
        {
re:
            printf("\t\tע�⣡�����ֻ������6������\n\t\t����6�γ��򽫻��Զ�����.\n\n");
            printf("\t\t��ǰ�����������%d��\n\n", x+1);
            x++;
            if (x == 6)
            {
                printf("�����δ��󣬱������Զ���ֹ!\n");
                getch();
                exit(1);
            }
            printf("      ����������: ") ;
            for (i = 0 ; i < 7; i ++)
            {
                mima[i] = getch() ;
                if (mima[i] == '\b')
                {
                    mo[i-1] = '\0' ;
                    i -= 2 ;
                    system("cls");
                    print();
                    printf("\n\n\t������ȷ!\n\n");
                    printf("      ����������: ");
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
                printf("��������������,����������!\n") ;
                system("pause");
                system("cls");
                goto re;
            }
        }

        t = rand() % 10000 ;
        puts("");
        printf("��֤�� :  ") ;
        printf("%04d\n",t);
        sprintf(str,"%04d",t) ;
        printf("��������֤��:") ;
        scanf("%s",arr) ;
        if (strcmp(str,arr) == 0)
            system("cls");
    }
    else if (2 == choice)
    {
        FILE * fq = fopen("�˻�����ϵͳ.txt", "a+");

        printf("�봴���˻�:");
        scanf("%s", name);
        printf("����������:");
        scanf("%s", mima);
        printf("��ȷ������:");
        scanf("%s", ss);

        if ( strcmp (ss, mima) )
        {
            printf("ǰ��������������벻һ�£�\n");
            printf("������ѡ��!\n");
            system("pause");
            system("cls");
            goto type;
        }

        fprintf(fq, "%s %s\n", name, mima);
        printf("�����ɹ���\n");
        fclose (fq);
        goto type;
    }
    else
        goto end;
    system("cls");


strat:
    printf("\n\n                \t\t��ӭʹ��ѧ��֤����ϵͳ\n\n");
    printf("        \t\t����������������������������������\n");
    printf("        \t\t��\tѧ �� �� �� ϵ ͳ       ��\n");
    printf("        \t\t��\t1. ����ѧ��֤����       ��\n");
    printf("        \t\t��\t2. �޸�ѧ��֤����       ��\n");
    printf("        \t\t��\t3. ����ѧ��֤�ɼ�       ��\n");
    printf("        \t\t��\t4. ����ѧ��֤����       ��\n");
    printf("        \t\t��\t5. ɾ��ѧ��֤����       ��\n");
    printf("        \t\t��\t6. ��ӡѧ��֤��Ϣ       ��\n");
    printf("        \t\t��\t7. ׷��ѧ��֤����       ��\n");
    printf("        \t\t��\t8. ����ѧ��֤����       ��\n");
    printf("        \t\t��\t9. ����ѧ��֤����       ��\n");
    printf("        \t\t��\t0. ��������             ��\n");
    printf("        \t\t����������������������������������\n");
    printf("        \n\n\t\t��ѡ�������ʽ:");
choice:
    scanf(" %c", &flage);
    if (flage < '0' || flage > '9')
    {
        printf("��������������������������(0~9):\n");
        goto  choice;
    }

    if (0 == time && flage != '1' && flage != '9' && flage != '0')
    {
        printf("���ļ�ĿǰΪ�գ���ѡ������(1)���ߵ���(9)\n");
        goto  choice;
    }
    switch (flage - '0')
    {
    case 1:
        system("cls");
        ti = 1;
        printf("������ѧ������:");
        scanf("%d", &len);//����ѧ������
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
    printf("        \t\t����������������������������������\n");
    printf("        \t\t��\t    ������ʹ�����      ��\n");
    printf("        \t\t��\t     ��ӭ�ٴ�ʹ��       ��\n");
    printf("        \t\t��\t                        ��\n");
    printf("        \t\t��\tָ����ʦ:               ��\n");
    printf("        \t\t��\t         ��������ʦ     ��\n");
    printf("        \t\t��\t�� �� ��:               ��\n");
    printf("        \t\t��\t         ������         ��\n");
    printf("        \t\t��\t         ����ȫ         ��\n");
    printf("        \t\t��\t         л����         ��\n");
    printf("        \t\t��\t         ��  ��         ��\n");
    printf("        \t\t��\t         ��  ٻ         ��\n");
    printf("        \t\t��\t                        ��\n");
    printf("        \t\t����������������������������������\n");

    return 0;
}
