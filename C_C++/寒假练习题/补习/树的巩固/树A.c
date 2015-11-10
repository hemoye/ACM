#include <stdio.h>
#define MAXN 100
typedef struct node {
	struct node *left, *right;
	char ch;
}Node ;
char str[MAXN], i;
Node *q[MAXN];
int front, rear;
void bfs(Node *root)
{
	q[rear++] = root;
	while ( front < rear ) {
		Node *u = q[front++];
		if ( u->ch != '#' )	printf("%c", u->ch);
		if ( u->left != NULL )	q[rear++] = u->left;
		if ( u->right != NULL )	q[rear++] = u->right;
		free(u);
	}
}
void Creat(Node **root)
{
	if ( str[i] == '\0' )	return ;
	if ( str[i] == '#' ) {
		*root = NULL;
		i ++;
	}
	else {
		*root = (Node *)malloc(sizeof(Node));
		(*root)->ch = str[i];
		i ++;
		Creat(&(*root)->left);
		Creat(&(*root)->right);
	}
}
void show_pre(Node *pT)
{
	if ( pT != NULL ) {
		printf("%c", pT->ch);
		show_pre(pT->left);
		show_pre(pT->right);
	}
}
void show_in(Node *pT)
{
	if ( pT != NULL ) {
		show_in(pT->left);
		printf("%c", pT->ch);
		show_in(pT->right);
	}
}
void show_last(Node *pT)
{
	if ( pT != NULL ) {
		show_last(pT->left);
		show_last(pT->right);
		printf("%c", pT->ch);
	}
}
int main(void)
{
	Node *root;
	while ( ~scanf("%s", str) ) {
		i = 0;
		Creat(&root);
		show_pre(root); putchar(' ');
		show_in(root); putchar(' ');
		show_last(root); putchar(' ');
		bfs(root);
		puts("");
	}
	return 0;
}
