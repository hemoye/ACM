/**����������
        ���ڸ�����n����a1, a2...an;���������������֮�ͣ����õ�һ�������С�
        �ظ�������������������һ�����������������m����������Щ���޹�
    ����˼·��
        ���Կ���һ��n�ζ���ʽ��չ��ʽ�����ڼ����ϵ����m�ı���
**/
#include <iostream>
#define  MAXN 40

using namespace std;

int main( void )
{
    int m, n;
    int arrAy[MAXN];
    int Quad[MAXN];

    while ( cin >> n >> m ){
        for ( int i = 0; i < n; i++ ){
            cin >> arrAy[i];
        }
        Quad[0] = 1;
        for ( int i = 1; i < n; i++ ){
            Quad[i] = Quad[i-1] * ( n - i ) / i;
        }
        for ( int i = 0; i < n; i++ ){
            cout << Quad[i] << " ";
        }
        cout << endl;
        for ( int i = 0; i < n; i++ ){
            if ( 0 == Quad[i] % m ){
                cout << "���" << i + 1 << "��" << arrAy[i] << "��ֵ�޹�" << endl;
            }
        }
    }

    return 0;
}
