#include <iostream>

using namespace std;

typedef struct Node
{
    double ratio;
    double index;
    struct Node * Next;
} *NodePtr;

void Creat( NodePtr );
void add( NodePtr , NodePtr );
void Sort( NodePtr H );
void Traverse( NodePtr );

int main( void )
{
    NodePtr Head1 = new Node;
    NodePtr Head2 = new Node;

    Creat( Head1 );
    Creat( Head2 );

    add( Head1, Head2 );
    delete Head2;
    Sort( Head1 );

    Traverse( Head1 );
    delete Head1;

    cin.get();

    return 0;
}
void Creat( NodePtr H )
{
    NodePtr p1 = H;
    H->Next = NULL;
    double m, n;

    while ( cin >> m >> n )         //��������
    {
        if ( 0 == m && 0 == n )
            break;
        NodePtr p2 = new Node;
        p2->ratio = m;
        p2->index = n;
        p1->Next = p2;
        p1 = p2;
    }
    NodePtr p2 = new Node;          //�ڱ�β�ഴ��һ���սڵ�����������
    p2->index = p2->ratio = 0;
    p1->Next = p2;
    p2->Next = NULL;

    return ;
}
void add( NodePtr H1, NodePtr H2 )
{
    NodePtr p1, p2;

    for ( p1 = H1->Next; p1->Next; p1 = p1->Next )
        for ( p2 = H2; p2->Next->Next; p2 = p2->Next )
            if ( p1->index == p2->Next->index )             //�ϲ�ͬ����
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

    for ( q->Next = H; q ; q = q->Next )                    //����
        for ( p = H; p->Next->Next; p = p->Next )
            if ( p->Next->index > p->Next->Next->index )
            {
                temp = p->Next->Next;
                p->Next->Next = temp->Next;
                temp->Next = p->Next;
                p->Next = temp;
            }
    delete q;   //�ͷ��ڴ�

    return ;
}
void Traverse( NodePtr H )
{
    cout << endl << "AddPolyn(A,B);\nA = ";

    while (  H = H->Next )
    {
        cout << H->ratio;
        break;
    }
    if ( H->index > 0 )
        cout << "X^" << H->index;

    while ( H->Next )
    {
        H = H->Next;
        if ( 0 == H->ratio )        //��ʽ���  �����0�����
            continue;

        if ( H->ratio > 0 )
            cout << " + " << H->ratio;//�ж�����
        else
            cout << " " << H->ratio;

        if ( H->index > 0 )             //���ָ���Ĵ�С
            cout << "X^" << H->index;
    }
    cout << endl;

    return ;
}
