#include <iostream>
#include <cstdlib>
#include <vector>
#define  MAXNUM_VERTEX 20      /**最多20个顶点**/
#define  MAXNUM_EDGE 21

using namespace std;

struct Edge {
    int v, w;
    int weight;
} ;

struct Graph {
    int vertex[MAXNUM_VERTEX];
    Edge edge[MAXNUM_EDGE];
    int num_vertex, num_edge;
} ;

Graph graph;        /**声明为全局变量**/

bool search_vertex( int );
void kruskal( void );
void creat_graph( void );
void sort_by_weight( void );
void print_edge( void );
int  find_set( vector<int> & parent, int );
inline void makeset( vector<int> & );
inline void merge( vector<int> & , int , int );

int main( void )
{
    creat_graph();
    sort_by_weight();
    print_edge();
    kruskal();

    return 0;
}
bool search_vertex( int ver )
{
    for ( int i = 0; i < graph.num_vertex; i++ ){
        if ( ver == graph.vertex[i] ){
            return true;
        }
    }
    cout << " The vertex " << ver << " you input is not exist!" << endl;
    return false;
}
void sort_by_weight( void )
{
    int i, j;
    for ( i = 1; i < graph.num_edge; i++ ){
        Edge temp = graph.edge[i];
        for ( j = i - 1; j >= 0 && graph.edge[j].weight > temp.weight; j-- ){
            graph.edge[j+1] = graph.edge[j];
        }
        graph.edge[j+1] = temp;
    }
    return ;
}
inline void makeset( vector<int> & arrAy )
{
    for ( int i = 0; i < arrAy.size(); i++ ){
        arrAy[i] = i;
    }
    return ;
}
inline void merge( vector<int> & parent, int i, int j )
{
    parent[i] = j;
}
int find_set( vector<int> & parent, int i )
{
    if ( i != parent[i] ){
        i = parent[i];
    }
    return i;
}
void print_edge( void )
{
    cout << "The graph you input as follow: " << endl;
    for ( int i = 0; i < graph.num_edge; i++ ){
        cout << graph.edge[i].v << "-" << graph.edge[i].w << " the weight is : " << graph.edge[i].weight;
    }
    return ;
}
void creat_graph( void )
{
    cout << "Input the number of vertex in the graph." << endl;
    cin >> graph.num_vertex;
    cout << "Input the vertex of graph, like 1, 2." << endl;
    for ( int i = 0; i < graph.num_vertex; i++ ){
        cin >> graph.vertex[i];
    }
    cout << "Input the number of edge in the graph." << endl;
    cin >> graph.num_edge;
    cout << "Input the edge of graph and the weight of line, like 1-2 5" << endl;
    for ( int i = 0; i < graph.num_edge; i++ ){
creat:
        int a, c, d;
        char b;
        cin >> a >> b >> c >> d;
        if ( search_vertex( a ) && search_vertex( c ) ){
            graph.edge[i].v = a;
            graph.edge[i].w = c;
            graph.edge[i].weight = d;
        }
        else {
            goto creat;
        }
    }
}
void kruskal( void )
{
    int num_ver = graph.num_vertex;
    int count = 0;
    vector<int> parent_ver;
    parent_ver.resize( num_ver );
    makeset( parent_ver );

    cout << "The edge of min tree as follow : " << endl;
    for ( int i = 0; i < num_ver && count < num_ver - 1; i++ ){
        int m = graph.edge[i].v;
        int n = graph.edge[i].w;
        int w = graph.edge[i].weight;
        if ( find_set( parent_ver, m ) !=  find_set( parent_ver, n ) ){
            cout << m << " " << n << " " << w << endl;
            merge( parent_ver, m, n );
            count++;
        }
    }
    return ;
}
