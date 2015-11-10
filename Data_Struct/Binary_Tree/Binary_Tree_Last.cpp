#include <cstdio>

typedef struct Node
{
	int data;
	struct Node * left;
	struct Node * right;
} *pNode;

pNode Create()
{
    int x;
    scanf("%d", &x);

    if (x < 10){
        pNode Root = new Node;
        Root->data = x;
        Root->left = Create();
        Root->right = Create();

        return Root;
    }
    else    return NULL;
}

void Last(pNode T)
{
	if (T){
		Last(T->left);
		Last(T->right);
		printf("%d ", T->data);
	}
	return ;
}

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);

	pNode Tree = Create();

	Last(Tree);
	puts("");

	return 0;
}