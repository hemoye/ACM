#include <iostream>
#include <cstring>
#include <vector>
#define  MAXN 10

using namespace std;
vector<int> G[MAXN];                    /**��������**/
/**
    vector��STL�еĿɱ䳤���飬���G��һ��"����MAXN�У���ÿ�г��ȿ��Բ�ͬ��
    �ġ���ά���顰.
    �������������±���ʣ���������resize()�ı��С.������push_back()������
    β�����������
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
        G[u].push_back( v );                    /**�������������һ������**/
        G[v].push_back( u );                    /**push_pop���÷���ɾ����������һ������**/
    }
    return ;
}
void dfs( int u, int parent )                   /**�ݹ�ת��Ϊ��uΪ����������u�ĸ��ڵ���parent**/
{
    int d = G[u].size();/**���u���ڽ��ĸ���**/
    /**
        ���u���������ڵ㶼����G[u]�У���G[u[.size()��ȡu�����ڽ��ĸ���.
        G[u][i]��ʾ���е�i�����ڽڵ�.����vector�ǿɱ䳤�ģ��������ά���顰
        ռ�õĿռ���O(n)��������O(n^2).
    **/
    for ( int i = 0; i < d; i++ ){
        int v = G[u][i];/**���u�ĵ�i�����ڽ��**/
        if ( v != parent ){
            dfs( v, p[v] = u );/**��v�ĸ�����Ϊu��Ȼ��ݹ�ת����vΪ��������**/
            cout << v << " of the parent node is " << u << endl;
        }
    }
    return ;
}
