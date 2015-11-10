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

    while ( scanf("%d", &number) != EOF )   //����ѧ������
    {
        if ( 0 == number )                  //ѧ����Ϊ0ʱ��������
            break;
        scanf("%d%d", &problem, &gread);    //��������������Լ��޶�����

        struct Node temp, stud[MAX];     //����ѧ����Ŀ
        int a[MAX];                     //����������Ŀ
        int tt, x, count = 0;               //��������

        for ( i = 1; i <= problem; i++ )
            scanf("%d", &a[i]);//����ÿһ������ķ�ֵ

        for ( i = 0; i < number; i++ )      //�洢��һ������number��ѧԱ����Ϣ
        {
            scanf("%s%d", stud[i].name, &stud[i].Ques_num);     //���ֺͻش��������Ŀ
            stud[i].total = 0;

            for ( x = 0; x < stud[i].Ques_num; x++ )
            {
                scanf("%d", &tt);           //�ش�����ı��
                stud[i].total += a[tt];     //�ۼ�ÿһ������ķ�ֵ(��ѧ�����ܷ���)
            }
            if ( stud[i].total >= gread )   //�ۼӼ����ѧ����Ŀ
                count++;
        }

        for ( i = 1; i < number; i++ )//ð�ݷ���ѧ������
            for ( j = 0; j < number - i; j++ )
                if ( strcmp(stud[j].name, stud[j+1].name) > 0 )
                {
                    temp = stud[j];
                    stud[j] = stud[j+1];
                    stud[j+1] = temp;
                }

        for ( i = 1; i < number; i++ )//ð�ݷ�����������
            for ( j = 0; j < number - i; j++ )
                if ( stud[j].total < stud[j+1].total )
                {
                    temp = stud[j];
                    stud[j] = stud[j+1];
                    stud[j+1] = temp;
                }

        printf("%d\n", count);      //�����������

        for ( i = 0; i < number; i++ )          //�������ѧ����������Ϣ
            if ( stud[i].total >= gread )
                printf("%s %d\n", stud[i].name, stud[i].total);
    }

    return 0;
}
