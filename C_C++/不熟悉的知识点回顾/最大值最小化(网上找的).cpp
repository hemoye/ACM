#include <iostream>
#include <ctime>
using namespace std;
#define N 6
#define INF 1000

int juge(int a[],int mid,int k)
{
    int i;
    int seg=0;
    int sum=0;
    for(i=0; i<N; i++)
    {
        sum+=a[i];
        if(sum>mid) //从左到右将数组元素之和与mid比较，如是大于则再起一段，最后看段的大小
        {
            sum=a[i];
            seg++;
        }
    }
    if(seg>=k) //若是段超过3，则必然不和条件
        return 0;
    else
        return 1;
}

int value(int a[],int low,int high,int segment) //分治法求解
{
    if(low>high)
        return high+1;
    else
    {
        int mid=(low+high)/2;
        if(juge(a,mid,segment)==1) //如果试验数mid符合要求，递归到前一半
            return value(a,low,mid-1,segment);
        else//如果试验数mid不符合要求，递归到后一半
            return value(a,mid+1,high,segment);
    }
}

int main()
{
    int a[N];
    int n;

    for(int ifor=0; ifor<N; ifor++)
        cin >> a[ifor];

//int a[N]={9,19,15,13,13,9,14,1,1,7};
    int m;
    cin >> m;
    cout<<endl;
//求出队列中所有数的和max，还要求出当中最小的数min
    int min=INF,max=0;
    for(int i=0; i<N ; i++)
    {
        max+=a[i];      //求数列的和
        if(a[i]<min)
            min=a[i];   //求数列的最小值
    }
    cout<<endl;
    int tem=value(a,min,max,m); //调用value函数求值
    cout<<tem<<endl;

    return 0;
}
