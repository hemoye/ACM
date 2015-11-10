#include <iostream>
#define  MAXN 40

int main( void )
{
    using namespace std;

    int n;
    int arrAy[MAXN];
    int result[MAXN];

    cout << "Please input the number of senquen: ";
    cin >> n;
    cout << "Please input the number: ";
    for ( int i = 0; i < n; i++ ){
        cin >> arrAy[i];
    }
    result[0] = arrAy[0];                       /**把第一个元素放进排序空间**/
    for ( int i = 1; i < n; i++ ){
        for ( int j = 1; j <= i; j++ ){         /**对第0~i个元素进行排序**/
            if ( arrAy[i] >= result[i-j] ){     /**如果第i位大于第i-j位则把第i位置的数据放在第i-j的后一位**/
                result[i-j+1] = arrAy[i];
                break;
            }
            else {                              /**否则后移一位**/
                result[i-j+1] = result[i-j];
            }
            if ( i == j ){                      /**如果第i位的数组元素是最小的，则会被放置到排序空间的第一位**/
                result[0] = arrAy[i];
            }
        }
    }
    for ( int i = 0; i < n; i++ ){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
