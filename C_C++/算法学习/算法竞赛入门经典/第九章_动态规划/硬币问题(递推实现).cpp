#include <iostream>
#include <cstring>
#define  MAXN 40
#define  INF 32767

using namespace std;

int main( void )
{
    int number, money;
    int Coins[MAXN];
    int Max[MAXN], Min[MAXN];

    cout << "Please input number:";
    cin >> number;
    cout << "Please input money:";
    cin >> money;
    for ( int i = 0; i < number; i++ ){
        cin >> Coins[i];
    }
    memset( Max, -INF, sizeof( Max ) );
    memset( Min, INF, sizeof( Min ) );
    Max[0] = Min[0] = 0;
    for ( int i = 1; i <= money; i++ ){
        for ( int j = 0; j < number; j++ ){
            if ( i >= Coins[j] ){
                int temp = Min[i-Coins[j]] + 1;
                Min[i] = Min[i] > temp ? Min[i] : temp;
                Max[i] = Max[i] < temp ? Max[i] : temp;
            }
        }
    }
    cout << "The most: " << Min[money] << endl;
    cout << "The least: " << Max[money] << endl;

    return 0;
}
