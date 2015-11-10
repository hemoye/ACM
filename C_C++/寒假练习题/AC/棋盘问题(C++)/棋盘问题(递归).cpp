int vis[MAX], mat[MAX][MAX];
int m, n;
int count = 0, num = 0;
void dfs( int x )
{
    if ( x >= n )
        return ;
    if ( num == m )
        count++;
    for ( int y = 0; y < n; y++ )
        if ( !vis[y] && mat[x][y] == '#' )
        {
            vis[y] = 1;
            num++;
            dfs( x + 1 );
            vis[y] = 0;
            num--;
        }
    dfs( x + 1 );
}
