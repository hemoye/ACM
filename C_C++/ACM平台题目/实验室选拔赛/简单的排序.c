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
小豪同学最近在惆怅中啊。。。。为什么呢，因为四级又来了，所以他准备把单词给啃了，但是太久没有接触英语了，他决定先从单词长度最长的开始背，如果长度一样那么按字典序背诵，所以你的任务就是输出他要背的单词的顺序

排序规则

1：按长度排序，长的靠前

2：如果长度相等，则按字典序排序

3：规定所有的大写的字母的字典序都在在小写的前面(跟ASIC码一样)

Input

先输入测试数据的组数n，然后接下来是n组测试数据，每组测试数据包括一个整数m,接下来是m行字符串（长度小于100）！！

Output

按给定的规则输出结果，注意格式是先输出Case i:

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
