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
        if(sum>mid) //�����ҽ�����Ԫ��֮����mid�Ƚϣ����Ǵ���������һ�Σ���󿴶εĴ�С
        {
            sum=a[i];
            seg++;
        }
    }
    if(seg>=k) //���Ƕγ���3�����Ȼ��������
        return 0;
    else
        return 1;
}

int value(int a[],int low,int high,int segment) //���η����
{
    if(low>high)
        return high+1;
    else
    {
        int mid=(low+high)/2;
        if(juge(a,mid,segment)==1) //���������mid����Ҫ�󣬵ݹ鵽ǰһ��
            return value(a,low,mid-1,segment);
        else//���������mid������Ҫ�󣬵ݹ鵽��һ��
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
//����������������ĺ�max����Ҫ���������С����min
    int min=INF,max=0;
    for(int i=0; i<N ; i++)
    {
        max+=a[i];      //�����еĺ�
        if(a[i]<min)
            min=a[i];   //�����е���Сֵ
    }
    cout<<endl;
    int tem=value(a,min,max,m); //����value������ֵ
    cout<<tem<<endl;

    return 0;
}
