#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
const int MAXN = 1004;
using namespace std;

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int n;
    string str;
    string arrAy[MAXN];
    while ( ~scanf("%d", &n ) && n ){
        int j, x(0);
        int num[MAXN];
        memset( num, 0, sizeof(num) );
        for ( int i = 0; i < n; i++ ){
            cin >> str;
            for ( j = 0; j < x; j++ ){
                if ( arrAy[j] == str ){
                    num[j]++;
                    break;
                }
            }
            if ( j == x ){
                arrAy[x] = str;
                num[x]++;
                x++;
            }
        }
        int ans(0);
        for ( int i = 0; i < x; i++ ){
            if ( num[ans] < num[i] )    ans = i;
        }
        cout << arrAy[ans] << endl;
    }

    return 0;
}
