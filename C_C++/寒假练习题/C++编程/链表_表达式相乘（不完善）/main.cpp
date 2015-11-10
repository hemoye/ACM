#include <iostream>

using namespace std;

typedef struct Node
{
    double ratio;
    double index;
    struct Node * Next;
} *NodePtr;

void Creat( NodePtr );
void add( NodePtr );
void mulp( NodePtr , NodePtr );
void Sort( NodePtr H );
void Traverse( NodePtr );
NodePtr Head3 = new Node;

int main( void )
{
    NodePtr Head1 = new Node;
    NodePtr Head2 = new Node;

    NodePtr p = new Node;
    Head3->Next = p;
    p->index = p->ratio = 0;
    p->Next = NULL;

    Creat( Head1 );
    Creat( Head2 );

    mulp( Head1, Head2 );
    cout << "3" << endl;
    delete Head1;
    delete Head2;

    //Sort( Head3 );

    Traverse( Head3 );
    delete Head3;

    return 0;
}
void Creat( NodePtr H )
{
    NodePtr p1 = H;
    H->Next = NULL;
    double m, n;

    while ( cin >> m >> n )         //创建聊表
    {
        if ( 0 == m && 0 == n )
            break;
        NodePtr p2 = new Node;
        p2->ratio = m;
        p2->index = n;
        p1->Next = p2;
        p1 = p2;
    }
    NodePtr p2 = new Node;          //在表尾多创建一个空节点有助于排序
    p2->index = p2->ratio = 0;
    p1->Next = p2;
    p2->Next = NULL;

    return ;
}
void mulp( NodePtr H1, NodePtr H2 )
{
    NodePtr p1, p2;

    for ( p1 = H1->Next; p1->Next; p1 = p1->Next )
    {
        NodePtr H = new Node;
        NodePtr p3 = H->Next;
        for ( p2 = H2->Next; p2->Next; p2 = p2->Next )
        {
            NodePtr temp = new Node;
            temp->ratio = p1->ratio * p2->ratio;
            temp->index = p1->index + p2->index;
            p3->Next = temp;
            p3 = temp;
        }
        NodePtr temp = new Node;          //在表尾多创建一个空节点有助于排序
        temp->index = temp->ratio = 0;
        p3->Next = temp;
        temp->Next = NULL;
        add( H );

        delete H;
    }

    return ;
}
void add( NodePtr H2 )
{
    NodePtr p1, p2;

    for ( p1 = Head3->Next; p1->Next; p1 = p1->Next )
        for ( p2 = H2; p2->Next->Next; p2 = p2->Next )
            if ( p1->index == p2->Next->index )             //合并同类项
            {
                NodePtr temp = p2->Next;
                p1->ratio += temp->ratio;
                p2->Next = temp->Next;
            }
    p1->Next = H2->Next;

    return ;
}
void Sort( NodePtr H )
{
    NodePtr p, temp;
    NodePtr q = new Node;

    for ( q->Next = H; q ; q = q->Next )                    //排序
        for ( p = H; p->Next->Next; p = p->Next )
            if ( p->Next->index > p->Next->Next->index )
            {
                temp = p->Next->Next;
                p->Next->Next = temp->Next;
                temp->Next = p->Next;
                p->Next = temp;
            }
    delete q;   //释放内存

    return ;
}
void Traverse( NodePtr H )
{
    cout << endl << "MulPolyn(A,B); \nA = ";

    H = H->Next;
    cout << H->ratio;
    if ( H->index > 0 )
        cout << "X^" << H->index;

    while ( H->Next )
    {
        H = H->Next;
        if ( 0 == H->ratio )        //格式输出  如果是0则不输出
            continue;

        if ( H->ratio > 0 )
            cout << " + " << H->ratio;//判断正负
        else
            cout << " " << H->ratio;

        if ( H->index > 0 )             //输出指数的大小
            cout << "X^" << H->index;
    }
    cout << endl;

    return ;
}
