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
    result[0] = arrAy[0];                       /**�ѵ�һ��Ԫ�طŽ�����ռ�**/
    for ( int i = 1; i < n; i++ ){
        for ( int j = 1; j <= i; j++ ){         /**�Ե�0~i��Ԫ�ؽ�������**/
            if ( arrAy[i] >= result[i-j] ){     /**�����iλ���ڵ�i-jλ��ѵ�iλ�õ����ݷ��ڵ�i-j�ĺ�һλ**/
                result[i-j+1] = arrAy[i];
                break;
            }
            else {                              /**�������һλ**/
                result[i-j+1] = result[i-j];
            }
            if ( i == j ){                      /**�����iλ������Ԫ������С�ģ���ᱻ���õ�����ռ�ĵ�һλ**/
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
