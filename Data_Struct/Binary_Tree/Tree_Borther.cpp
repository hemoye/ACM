#include <cstdio>

typedef struct Node
{
	int data;
	struct Node * Next;
	struct Node * Borther;
} *pNode;

pNode Create()
{
	int x;

	scanf("%d", &x);

	if (x > 9)	return NULL;

	pNode T = new Node;
	T->data = x;
	T->Borther = Create();
	T->Next = Create();
	return T;
}
void print(pNode T)
{
	printf("%d ", T->data);
	if (T->Borther)	print(T->Borther);
	if (T->Next)	print(T->Next);
	return ;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif
	printf("输入规则：请先输入根结点、然后是兄弟结点，兄弟结点全部输入完成之后才是子节点\n");

	pNode Root = Create();

	print(Root);
	puts("");
	
	return 0;
}