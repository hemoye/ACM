/**
    �����������ںڰ���д��N�����������ɵ�һ�����У��������²���:ÿһ�β�ȥ���е�������a��b��
Ȼ���������м���һ����a��b+1�������ȥֱ���ڰ���ʣ��һ�����������а����ֲ�����ʽ���õ�����
�У�����max����С��Ϊmin��������еļ����ΪM=max-min��
    ������񣺶��ڸ��������У���̼��������M��
**/

#include <iostream>
#define  MAXN 40

void Quick_Sort( int , int );
int  Find_Pos( int , int );

int arrAy[MAXN];

int main( void )
{
    using namespace std;
    int n;

    cin >> n;
    for ( int i = 0; i < n; i++ )
        cin >> arrAy[i];
    Quick_Sort( 0, n - 1 );

    int max = arrAy[0];
    for ( int i = 1; i < n; i++ )
        max = max * arrAy[i] + 1;

    int min = arrAy[n-1];
    for ( int i = n - 2; i >= 0; i-- )
        min = min * arrAy[i] + 1;
    cout << max << " " << min << endl;
    cout << max - min << endl;

    return 0;
}
void Quick_Sort( int low, int high )
{
    if ( low < high )
    {
        int pos = Find_Pos( low, high );
        Quick_Sort( low, pos - 1 );
        Quick_Sort( pos + 1, high );
    }
    return ;
}
int Find_Pos( int low, int high )
{
    int val = arrAy[low];

    while ( low < high )
    {
        while ( low < high && arrAy[high] >= val )
            high--;
        arrAy[low] = arrAy[high];
        while ( low < high && arrAy[low] <= val )
            low++;
        arrAy[high] = arrAy[low];
    }
    arrAy[low] = val;

    return low;
}
