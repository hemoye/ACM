#include <iostream>
#define  MAXN 40

void Merge_Sort( int , int );                           /**����**/
void Merge( int , int , int );                          /**�鲢**/

int arrAy[MAXN];

int main( void )
{
    using namespace std;
    int n;

    cout << "Please input the number of array: ";
    cin >> n;
    cout << "Please input the element of array: ";
    for ( int i = 0; i < n; i++ ){
        cin >> arrAy[i];
    }
    Merge_Sort( 0, n );
    for ( int i = 0; i < n; i++ ){
        cout << arrAy[i] << " ";
    }
    cout << endl;

    return 0;
}
void Merge_Sort( int low, int high )
{
    if ( low < high - 1 ){
        int mid = ( low + high ) / 2;       /**��ԭ����ֳ���������**/
        Merge_Sort( low, mid );             /**�ݹ����**/
        Merge_Sort( mid, high );
        Merge( low, mid, high );            /**�鲢�㷨**/
    }
    return ;
}
void Merge( int low, int mid, int high )
{
    int temp[MAXN];
    int i = low, x = low, y = mid;
    while ( x < mid && y < high ){          /**���鲢����κ�һ������ʱ���˳�ѭ��**/
        if ( arrAy[x] < arrAy[y] ){         /**�����������н�С������������ռ��ǰ��**/
            temp[i++] = arrAy[x++];
        }
        else {
            temp[i++] = arrAy[y++];
        }
    }
    if ( x >= mid ){                        /**�ж�����һ�������Ѿ���ȫ��ȡ��**/
        for ( int j = y; j < high; j++ ){   /**����ǵ�һ�������Ѿ���ȡ�꣬��ѵڶ�������ȫ�����Ƶ�����ռ�**/
            temp[i++] = arrAy[j];
        }
    }
    else {
        for ( int j = x; j < mid; j++ ){
            temp[i++] = arrAy[j];
        }
    }
    for ( i = low; i < high; i++ ){         /**������ռ��Ԫ�ظ��ƻ�ԭ����**/
        arrAy[i] = temp[i];
    }
    return ;
}
