#include <iostream>
#define  MAXN 40

void Merge_Sort( int , int );                           /**分治**/
void Merge( int , int , int );                          /**归并**/

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
        int mid = ( low + high ) / 2;       /**将原数组分成两个数组**/
        Merge_Sort( low, mid );             /**递归调用**/
        Merge_Sort( mid, high );
        Merge( low, mid, high );            /**归并算法**/
    }
    return ;
}
void Merge( int low, int mid, int high )
{
    int temp[MAXN];
    int i = low, x = low, y = mid;
    while ( x < mid && y < high ){          /**当归并完成任何一个数组时就退出循环**/
        if ( arrAy[x] < arrAy[y] ){         /**把两个数组中较小的数放在排序空间的前面**/
            temp[i++] = arrAy[x++];
        }
        else {
            temp[i++] = arrAy[y++];
        }
    }
    if ( x >= mid ){                        /**判断是哪一个数组已经被全部取完**/
        for ( int j = y; j < high; j++ ){   /**如果是第一段数组已经被取完，则把第二段数组全部复制到排序空间**/
            temp[i++] = arrAy[j];
        }
    }
    else {
        for ( int j = x; j < mid; j++ ){
            temp[i++] = arrAy[j];
        }
    }
    for ( i = low; i < high; i++ ){         /**把排序空间的元素复制回原数组**/
        arrAy[i] = temp[i];
    }
    return ;
}
