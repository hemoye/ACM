#include <cstdio>

typedef struct Node {
    char data;
    struct Node * Next;
} *pNode;

void print(pNode Head)
{
    while (Head->Next){
        Head = Head->Next;
        printf("%c ", Head->data);
    }
    puts("");

    return ;
}

int main(int agrc, char *agrv[])
{
    pNode Head = new Node;

    Head->Next = NULL;

    for (int i = 0; i < 4; i++){
        pNode p = new Node;
        scanf(" %c", &p->data);
        p->Next = Head->Next;
        Head->Next = p;
    }
    print(Head);

    return 0;
}
