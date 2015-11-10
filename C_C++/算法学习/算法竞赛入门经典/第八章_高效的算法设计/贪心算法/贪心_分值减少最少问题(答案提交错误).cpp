#include <iostream>
#define  MAXN 40
#define  Swap( a, b, t ) t = a, a = b, b = t

struct Node
{
    int deadline;
    int time;
} ;

int main( void )
{
    using namespace std;

    int t, n;
    char name[MAXN];
    Node test[MAXN];
    Node temp;

    cin >> t;
    while ( t-- ){
        cin >> n;
        for ( int i = 0; i < n; i++ ){
            cin >> name >> test[i].deadline >> test[i].time;
        }
        int change = 1;
        for ( int i = 1; i < n && change; i++ ){
            change = 0;
            for ( int j = 0; j < n - i; j++ ){
                if ( test[j].deadline > test[j+1].deadline ){
                    Swap( test[j], test[j+1], temp );
                    change = 1;
                }
            }
        }
        int min( 0 ), sum( 0 );
        for ( int i = 0; i < n; i++ ){
            sum += test[i].time;
            if ( test[i].deadline < sum ){
                min += sum - test[i].deadline;
            }
        }
        cout << min << endl;
    }

    return 0;
}
