#include <iostream>
#include <cstring>
#define  MAXSIZE 40

typedef struct Node
{
    //char name[MAXSIZE];
    char * name;
    double weight;
    int hot;
} *NodePtr;

void Cite( Node & , char * , double , int );        //�������õ�ʹ��

int main( void )
{
    using namespace std;

    Node Company;                                   //����һ���ṹ�����͵ı���Company

    Cite( Company, "MiIlennium Munch", 2.85, 350 );

    cout << "Name  : " << Company.name << endl;
    cout << "Weight: " << Company.weight << endl;
    cout << "Hot   : " << Company.hot << endl;

    return 0;
}
void Cite( Node &M, char * ptr, double w, int h )
{
    using namespace std;

    //strcpy( M.name, ptr );
    M.name = ptr;
    M.weight = w;
    M.hot = h;

    return ;
}
