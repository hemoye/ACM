#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 54;
string arrAy[MAXN];

bool strCMP( string s, string c )
{
    return s + c > c + s;
}

int main( int agrc, char *agrv[] )
{
#ifndef ONLINE_JUDGE
    freopen( "test.in", "r", stdin );
#endif
    int n;
    while ( ~scanf("%d", &n ) && n ){
        for ( int i = 0; i < n; i++ )   cin >> arrAy[i];
        sort( arrAy, arrAy + n, strCMP );
        for ( int i = 0; i < n; i++ )   cout << arrAy[i];
        puts("");
    }

    return 0;
}
