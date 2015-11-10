#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#define  MAXN 101

using namespace std;

string stp[MAXN];
int vis[MAXN];

struct Word
{
    char sta, end;
} word[101];
int  n;
int DFS(char ch)
{
    if ( ch == 'm' )
        return 1;

    int i ;
    for (i = 0; i < n; ++i)
        if ( word[i].sta == ch && !vis[i] )
        {
            vis[i] = 1;
            if (DFS(word[i].end))
                return 1;
            vis[i] = 0;
        }
    return 0;
}
int main( void )
{
    string str;
    while ( cin>>str )
    {
        n = 0;
        memset(vis, 0, sizeof(vis));
        while ( str != "0" )
        {
            word[n].sta = str[0];
            word[n].end = str[str.length() - 1];
            n++;
            cin>>str;
        }
        if ( DFS( 'b' ) )
            cout<<"Yes."<<endl;
        else
            cout<<"No."<<endl;
    }
    return 0;
}
