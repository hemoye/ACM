#include <stdio.h>
#define   1000

struct Node
{
    char name[MAX];
    int Ques_num;
    int total;
};

int main( void )
{
    int number, problem, gread;
    int i, j;

    while ( scanf("%d", &number) != EOF )   //输入学生人数
    {
        if ( 0 == number )                  //学生数为0时结束程序
            break;
        scanf("%d%d", &problem, &gread);    //输入问题的数量以及限定分数

        struct Node temp, stud[MAX];     //声明学生数目
        int a[MAX];                     //声明问题数目
        int tt, x, count = 0;               //定义声明

        for ( i = 1; i <= problem; i++ )
            scanf("%d", &a[i]);//储存每一个问题的分值

        for ( i = 0; i < number; i++ )      //存储第一个至第number个学员的信息
        {
            scanf("%s%d", stud[i].name, &stud[i].Ques_num);     //名字和回答问题的数目
            stud[i].total = 0;

            for ( x = 0; x < stud[i].Ques_num; x++ )
            {
                scanf("%d", &tt);           //回答问题的编号
                stud[i].total += a[tt];     //累加每一个问题的分值(即学生的总分数)
            }
            if ( stud[i].total >= gread )   //累加及格的学生数目
                count++;
        }

        for ( i = 1; i < number; i++ )//冒泡法按学号排序
            for ( j = 0; j < number - i; j++ )
                if ( strcmp(stud[j].name, stud[j+1].name) > 0 )
                {
                    temp = stud[j];
                    stud[j] = stud[j+1];
                    stud[j+1] = temp;
                }

        for ( i = 1; i < number; i++ )//冒泡法按分数排序
            for ( j = 0; j < number - i; j++ )
                if ( stud[j].total < stud[j+1].total )
                {
                    temp = stud[j];
                    stud[j] = stud[j+1];
                    stud[j+1] = temp;
                }

        printf("%d\n", count);      //输出及格人数

        for ( i = 0; i < number; i++ )          //输出及格学生的所有信息
            if ( stud[i].total >= gread )
                printf("%s %d\n", stud[i].name, stud[i].total);
    }

    return 0;
}
