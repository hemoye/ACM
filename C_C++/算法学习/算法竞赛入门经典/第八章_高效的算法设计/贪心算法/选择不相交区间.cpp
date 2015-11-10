#include <iostream>
#include <algorithm>
#define  MAXN 40

struct Node
{
    int a;
    int b;
    bool operator < ( const Node & S ) const{
        return b < S.b;
    }
} ;

int main( void )
{
    using namespace std;

    int n;
    Node arrAy[MAXN];

    while ( cin >> n ){
        if ( 0 == n )
            break;
        int count = 0;
        int end = -1;

        for ( int i = 0; i < n; i++ ){
            cin >> arrAy[i].a >> arrAy[i].b;
        }
        sort ( arrAy, arrAy + n );

        for ( int i = 0; i < n; i++ ){
            if ( end <= arrAy[i].a ){
                end = arrAy[i].b;
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}
