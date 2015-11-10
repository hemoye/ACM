#include <iostream>
#include <cstdlib>
#define  MAXN 40
#define  Swap( a, b, t ) t = a, a = b, b = t

struct Node
{
    int deadline;
    int time;
} ;

using namespace std;

Node test[MAXN];
int m, n, Min, total;

void print_pre( int , int );

int main( void )
{
    int t;
    char str[MAXN];

    cin >> t;
    while ( t-- ){
        cin >> n;
        for ( int i = 0; i < n; i++ ){
            cin >> str >> test[i].deadline >> test[i].time;
        }
        Min = 2147483647;
        print_pre( n, 0 );
        cout << Min << endl;
    }

    return 0;
}
void print_pre( int n, int cur )
{
    if ( n == cur ){
        total = 0;
        m = 0;
        for ( int i = 0; i < n; i++ ){
            total += test[i].time;
            if ( total - test[i].deadline > 0 ){
                m += total - test[i].deadline;
            }
        }
        if ( Min > m ){
            Min = m;
        }
    }
    else {
        Node temp;
        for ( int i = cur; i < n; i++ ){
            Swap( test[i], test[cur], temp );
            print_pre( n, cur + 1 );
            Swap( test[i], test[cur], temp );
        }
    }
}
