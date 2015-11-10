#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char ch;
    struct node *left,*right;
} node;                  // 定义节点的结构

node * creat(char *pre,char *in,int len);//构建函数
void print(node *head);//遍历函数

int main(void)
{
    char pre[30],in[30];    // 存储先序和中序遍历的序列
    node *head;
    head=(node*)malloc(sizeof(node));

    while(scanf("%s%s",pre,in)!=EOF)
    {
        head=creat(pre,in,strlen(pre));
        print(head);
        printf("\n");
    }
    return 0;
}

node * creat(char *pre,char *in,int len)  // 创建后序遍历的函数
{
    int k;
    if(len<=0)
        return NULL;
    node *head=(node*)malloc(sizeof(node));
    head->ch=*pre;
    char *p;
    for(p=in; p!=NULL; p++)
        if(*p==*pre)
            break;                 // 在中序遍历的序列中得到与先序相同的节点
    k=p-in;
    head->left=creat(pre+1,in,k);          //递归调用得到左子树
    head->right=creat(pre+k+1,p+1,len-k-1);//得到右子树

    return head;
}

void print(node *head)  // 打印后序遍历序列
{
    if(head == NULL)
        return ;
    printf("%c",head->ch);//后序输出
    print(head->left);
    print(head->right);

}

/*
二叉树的遍历算法在其他树操作的基础

已知先序和中序求二叉树的后序遍历算法核心是

1、从先序遍历中读入根节点

2、从中序遍历中找到与根节点相等的元素，以此节点将中序序列分成两个部分，左边的为二叉树的

   左子树，右边为二叉树的右子树；

3、递归调用上述步骤得到根节点的左右子树
*/
