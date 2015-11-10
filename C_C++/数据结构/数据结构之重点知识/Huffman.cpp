#include <iostream>
#include <cstdio>

struct Node {
    int data;
    Node * left;
    Node * right;
    Node * Next;
} ;

typedef Node *HuffNode;

void Pre_order( HuffNode );
void Creat_huffmantree( HuffNode );
HuffNode Creat_Node( int );
HuffNode Insert( HuffNode , HuffNode );

int main( int argc, char *argv[] )
{
    int n;
    HuffNode Root;

    printf("Please enter the length of the huffman-tree: ");
    scanf("%d", &n );
    Root = Creat_Node( n );
    Creat_huffmantree( Root );
    Pre_order( Root );
    puts("");

    return 0;
}
HuffNode Creat_Node( int n )
{
    HuffNode Head, pre;
    int x;

    pre = Head = NULL;
    while ( n-- ){
        scanf("%d", &x );
        HuffNode p = new Node;
        p->data = x;
        p->left = p->right = p->Next = NULL;
        pre->Next = p;
        pre = p;
    }
    return Head;
}
/**将节点s插入到有序的Huffman Root中**/
HuffNode Insert( HuffNode Root, HuffNode s )
{
    HuffNode p, q;
    if ( NULL == Root ){
        Root = s;
    }
    else {
        p = NULL;
        q = Root;
        while ( q && q->data < s->data ){
            p = q;
            q = q->Next;
        }
        s->Next = q;
        if ( NULL == p ){
            Root = s;
        }
        else {
            p->Next = s;
        }
    }
    return Root;
}
void Creat_huffmantree( HuffNode Root )
{
    HuffNode itself, next;

    while ( Root && Root->Next ){
        itself = Root;
        next = Root->Next;
        Root = next->Next;
        HuffNode s = new Node;
        s->Next = NULL;
        s->data = itself->data + next->data;
        s->left = itself;
        s->right = next;
        itself->Next = next->Next = NULL;
        Insert( Root, s );
    }
}
void Pre_order( HuffNode T )
{
    if ( NULL == T ){
        return ;
    }
    else {
        printf("%-6d", T->data );
        Pre_order( T->left );
        Pre_order( T->right );
    }
}
