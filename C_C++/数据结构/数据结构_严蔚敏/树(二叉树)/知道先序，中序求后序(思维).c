#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char ch;
    struct node *left,*right;
} node;                  // ����ڵ�Ľṹ

node * creat(char *pre,char *in,int len);//��������
void print(node *head);//��������

int main(void)
{
    char pre[30],in[30];    // �洢������������������
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

node * creat(char *pre,char *in,int len)  // ������������ĺ���
{
    int k;
    if(len<=0)
        return NULL;
    node *head=(node*)malloc(sizeof(node));
    head->ch=*pre;
    char *p;
    for(p=in; p!=NULL; p++)
        if(*p==*pre)
            break;                 // ����������������еõ���������ͬ�Ľڵ�
    k=p-in;
    head->left=creat(pre+1,in,k);          //�ݹ���õõ�������
    head->right=creat(pre+k+1,p+1,len-k-1);//�õ�������

    return head;
}

void print(node *head)  // ��ӡ�����������
{
    if(head == NULL)
        return ;
    printf("%c",head->ch);//�������
    print(head->left);
    print(head->right);

}

/*
�������ı����㷨�������������Ļ���

��֪�����������������ĺ�������㷨������

1������������ж�����ڵ�

2��������������ҵ�����ڵ���ȵ�Ԫ�أ��Դ˽ڵ㽫�������зֳ��������֣���ߵ�Ϊ��������

   ���������ұ�Ϊ����������������

3���ݹ������������õ����ڵ����������
*/
