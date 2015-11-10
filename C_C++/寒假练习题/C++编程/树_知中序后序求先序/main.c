#include<stdio.h>
#include<malloc.h>
typedef struct
{
    char data;
    struct Binnode *lchild;
    struct Binnode *rchild;
}Binnode, * Bintree;

void In_Pos_order(Bintree *t,char *s,char *r)
{
    char La[30],Lb[30],Ra[30],Rb[30];
    int i,len,length=strlen(r);
    if(length>0&&r[length-1]!='\0')
    {
        *t=(Binnode *)malloc(sizeof(Binnode));
        (*t)->data=r[length-1];
        for(i=0; s[i]!=r[length-1]; i++)
        {
            Ra[i]=s[i];
            La[i]=r[i];
        }
        len=i;
        Ra[len]='\0';
        La[len]='\0';
        for(i=len+1; i<strlen(s); i++)
        {
            Rb[i-len-1]=s[i];
        }
        Rb[i-len-1]='\0';
        for(i=len; i<strlen(r)-1; i++)
        {
            Lb[i-len]=r[i];
        }
        Lb[i-len]='\0';
        In_Pos_order(&(*t)->lchild,Ra,La);
        In_Pos_order(&(*t)->rchild,Rb,Lb);
    }
    else
    {
        *t=NULL;
    }
}
void Preorder1(Bintree t)
{
    if(t!=NULL)
    {
        printf("%c",t->data);
        Preorder1(t->lchild);
        Preorder1(t->rchild);
    }
}

int main()
{
    Bintree t;
    char in[30]="ABCEFGHD",pos[30]="ABFHGEDC";
    printf("输入中序遍历序列:");
    scanf("%s",in);
    printf("输入后序遍历序列:");
    scanf("%s",pos);
    In_Pos_order(&t,in,pos);
    Preorder1(t);
}
