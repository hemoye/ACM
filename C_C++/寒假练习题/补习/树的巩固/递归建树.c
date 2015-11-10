#include <stdio.h>
#include <stdlib.h>
typedef struct tree{
	int data;
	struct tree *left;
	struct tree *right;
}Tree ;
Tree *Creat(Tree *, int);
Tree *insert(Tree *, Tree *);
void btraver(Tree *);
void mtraver(Tree *);
void ltraver(Tree *);
int main(void)
{
	Tree *pT;
	int n;
	scanf("%d", &n);
	pT = Creat(pT, n);
	btraver(pT);
	puts("");
	mtraver(pT);
	puts("");
	ltraver(pT);
	return 0;
}
Tree *Creat(Tree *root, int n)   //root¸根
{
	Tree *p;
	root = NULL;
	int i;
	for(i = 0; i < n; i ++){
		p = (Tree *)malloc(sizeof(Tree));
		scanf("%d", &p->data);
		p->left = p->right = NULL;
		root = insert(root, p);
	}
	return root;
}
Tree *insert(Tree *root, Tree *p)
{
	if( root == NULL ){    //把新的结点给链接起来
		root = p;
	}
	else if( p->data < root->data ){      //下面两个都是进行比较，放左还是右
		root->left = insert(root->left, p);
	}
	else if( p->data >= root->data ){
		root->right = insert(root->right, p);
	}
	return root;
}
void btraver(Tree *pT)
{
	if( pT != NULL ){
		printf("%d ", pT->data);
		if( pT->left != NULL ){
			btraver(pT->left);
		}
		if( pT->right != NULL ){
			btraver(pT->right);
		}
	}
}
void mtraver(Tree *pT)
{
	if( pT != NULL ){
		if( pT->left != NULL ){
			mtraver(pT->left);
		}
		printf("%d ", pT->data);
		if( pT->right != NULL ){
		mtraver(pT->right);
		}
	}
}
void ltraver(Tree *pT)
{
	if( pT != NULL ){
		if( pT->left != NULL ){
			ltraver(pT->left);
		}
		if( pT->right != NULL ){
		ltraver(pT->right);
		}
		printf("%d ", pT->data);
	}
}
