#include <cstdio>

typedef struct Node
{
	int data;
	struct Node * left;
	struct Node * right;
} *pNode;

pNode Find(pNode Tree, int x);
pNode FindMin(pNode);
pNode FindMax(pNode);
pNode Insert(pNode Tree, int x);
pNode Delete(pNode Tree, int x);
pNode MakeEmpty(pNode Tree);
void  Order_Traversal(pNode Tree);

int main(int argc, char const *argv[])
{
    pNode Tree = NULL;

    Tree = Insert(Tree, 10);
	Insert(Tree, 9);
	Insert(Tree, 12);
	Insert(Tree, 11);
	Insert(Tree, 1);
	Insert(Tree, 20);	

	pNode Min = FindMin(Tree);
	pNode Max = FindMax(Tree);

	printf("Min: %d, Max: %d\n", Min->data, Max->data);

	Order_Traversal(Tree);
	puts("");

	Delete(Tree, 11);

	Order_Traversal(Tree);
	puts("");

	Tree = MakeEmpty(Tree);

	return 0;
}

pNode Insert(pNode Tree, int x)
{
	if (NULL == Tree){
		Tree = new Node;
		Tree->data = x;
		Tree->left = Tree->right = NULL;
	}
	else if (x > Tree->data)	Tree->right = Insert(Tree->right, x);
	else if (x < Tree->data)	Tree->left = Insert(Tree->left, x);

	return Tree;
}
pNode Delete(pNode Tree, int x)
{
	pNode Temp;

	if (x > Tree->data)	Tree->right = Delete(Tree->right, x);
	else if (x < Tree->data) Tree->left = Delete(Tree->left, x);
	else if (Tree->right && Tree->left) {
		Temp = FindMin(Tree->right);
		Tree->data = Temp->data;
		Tree->right = Delete(Tree->right, Tree->data);
	}
	else {
		Temp = Tree;
		if (Tree->left)	Tree = Tree->left;
		else Tree = Tree->right;
		delete Temp;
	}
	return Tree;
}
pNode MakeEmpty(pNode Tree)
{
	if (Tree){
		MakeEmpty(Tree->left);
		MakeEmpty(Tree->right);
		delete Tree;
	}
	return NULL;
}
pNode Find(pNode Tree, int x)
{
	if (NULL == Tree)	return NULL;
	if (x == Tree->data)	return Tree;
	else if (x > Tree->data)	Find(Tree->right, x);
	else 	Find(Tree->left, x);
}
pNode FindMin(pNode Tree)
{
	if (Tree->left) return FindMin(Tree->left);
	else return Tree;
}
pNode FindMax(pNode Tree)
{
	if (Tree->right) return FindMax(Tree->right);
	else return Tree;
}
void Order_Traversal(pNode Tree)
{
	if (Tree){
		Order_Traversal(Tree->left);
		printf("%d ", Tree->data);
		Order_Traversal(Tree->right);
	}
	return ;
}