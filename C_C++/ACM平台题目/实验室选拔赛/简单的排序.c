#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Num
{
    char str[100];
    int a;
};
int main(void)
{
    int n,m,i,j,k;
    k = 1;
    struct Num t,arr[100];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        for (i = 0; i < m; i++)
        {
            scanf("%s",arr[i].str);
            arr[i].a = strlen(arr[i].str);
        }
        for (i = 0; i < m-1; i++)
            for (j = i+1; j < m; j++)
            {
                if (arr[i].a<arr[j].a)
                {
                    t = arr[i];
                    arr[i] = arr[j];
                    arr[j]= t;
                }
                else if (arr[i].a == arr[j].a)
                {
                    if (strcmp(arr[i].str,arr[j].str)>0)
                    {
                        t = arr[i];
                        arr[i] = arr[j];
                        arr[j] = t;
                    }
                }
            }
        printf("Case %d:\n",k++);
        for (i = 0; i < m; i++)
            printf("%s\n",arr[i].str);
    }
    return 0;
}

/*
С��ͬѧ���������а���������Ϊʲô�أ���Ϊ�ļ������ˣ�������׼���ѵ��ʸ����ˣ�����̫��û�нӴ�Ӣ���ˣ��������ȴӵ��ʳ�����Ŀ�ʼ�����������һ����ô���ֵ����У��������������������Ҫ���ĵ��ʵ�˳��

�������

1�����������򣬳��Ŀ�ǰ

2�����������ȣ����ֵ�������

3���涨���еĴ�д����ĸ���ֵ�������Сд��ǰ��(��ASIC��һ��)

Input

������������ݵ�����n��Ȼ���������n��������ݣ�ÿ��������ݰ���һ������m,��������m���ַ���������С��100������

Output

�������Ĺ�����������ע���ʽ�������Case i:

Sample Input

2
3
Bb
aa
xxx
4
zzzz
xxx
bb
aa
Sample Output

Case 1:
xxx
Bb
aa
Case 2:
zzzz
xxx
aa
bb
*/
