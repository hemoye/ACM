#include <iostream>
#include <cstring>
#include <vector>
#define  MAXN 10

using namespace std;
vector<int> G[MAXN];                    /**超级数组**/
/**
    vector是STL中的可变长数组，因此G是一个"包含MAXN行，但每行长度可以不同“
    的”二维数组“.
    它不仅可以用下标访问，还可以用resize()改变大小.或者用push_back()在数组
    尾部添加新数据
**/
int p[MAXN-1];
int Root;

void Read_Tree( void );
void dfs( int , int );

int main( void )
{
    memset( p, -2, sizeof( p ) );
    Read_Tree();
    dfs( Root, -1 );

    return 0;
}
void Read_Tree( void )
{
    int u, v;
    int n;
    cout << "Please enter the size of nodes: ";
    cin >> n;
    cout << "First, Please enter the root node: ";
    cin >> Root;
    cout << "Please enter the n nodes: ";
    for ( int i = 1; i < n; i++ ){
        cin >> u >> v;
        G[u].push_back( v );                    /**在数组的最后添加一个数据**/
        G[v].push_back( u );                    /**push_pop的用法：删除数组的最后一个数据**/
    }
    return ;
}
void dfs( int u, int parent )                   /**递归转化为以u为根的子树，u的父节点是parent**/
{
    int d = G[u].size();/**结点u相邻结点的个数**/
    /**
        结点u的所有相邻点都放在G[u]中，用G[u[.size()获取u的相邻结点的个数.
        G[u][i]表示其中第i个相邻节点.由于vector是可变长的，这个”二维数组“
        占用的空间是O(n)，而不是O(n^2).
    **/
    for ( int i = 0; i < d; i++ ){
        int v = G[u][i];/**结点u的第i个相邻结点**/
        if ( v != parent ){
            dfs( v, p[v] = u );/**把v的父亲设为u，然后递归转化以v为根的子树**/
            cout << v << " of the parent node is " << u << endl;
        }
    }
    return ;
}
