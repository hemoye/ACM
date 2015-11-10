#include <cstdio>

typedef struct Node {
    int data;
    struct Node * left;
    struct Node * right;
} *pNode;

pNode Create()
{
    int x;
    scanf("%d", &x);

    if (x < 100){
        pNode Root = new Node;
        Root->data = x;
        Root->left = Create();
        Root->right = Create();

        return Root;
    }
    else    return NULL;
}
void First(pNode T)
{
    if (T){
        printf("%d ", T->data);
        First(T->left);
        First(T->right);
    }
}

int main(int agrc, char *agrv[])
{
    freopen("test.in", "r", stdin);
    pNode Root = Create();

    First(Root);
    puts("");

    return 0;
}
