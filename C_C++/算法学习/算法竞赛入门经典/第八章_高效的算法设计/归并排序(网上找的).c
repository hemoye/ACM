#include <stdio.h>
#include <stdlib.h>
#define N 30

void merge(int [],int,int,int);//归并排序数组合并函数声明
void mergesort(int [],int,int);//归并排序数组排序函数声明

//主函数
int  main( void )
{
    freopen( "test.txt", "r", stdin );
    int i,a1[N];
    int n;

    scanf("%d", &n );
    for(i=0; i<n; i++)
        scanf("%d", &a1[i]);

    mergesort(a1,0,n);

    for(i=0; i<n; i++)
        printf("%d ",a1[i]);
    puts("");
    getch();
    return 0;
}

//归并排序合并数组函数的具体实现
void merge(int a[],int low,int middle,int high)
{
    int h,i,j,k;
    int b[N];
    h=low;
    i=low;
    j=middle+1;

    while(h<=middle&&j<=high)
    {
        if(a[h]<=a[j])    //把小值放在前面
        {
            b[i]=a[h];
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h>middle)
        for(k=j; k<=high; k++)
        {
            b[i]=a[k];
            i++;
        }
    else
    {
        for(k=h; k<=middle; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    for(k=low; k<=high; k++)
        a[k]=b[k];
}

//归并排序函数的具体实现
void mergesort(int a[],int low,int high)
{
    int middle;
    if(low<high)
    {
        middle=(low+high)/2;
        mergesort(a,low,middle);
        mergesort(a,middle+1,high);
        merge(a,low,middle,high);
    }
}
