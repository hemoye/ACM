#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 110
#define MAXNUMBER 32727
typedef struct QHTNode{
    char c;      //�洢�����ݣ�Ϊһ���ַ�
    int weight; //�ڵ�Ȩ��
    int parent;//���ڵ��������е�λ������
    int lchild;//�����������е�λ������
    int rchild;//�Һ����������е�λ������
}HTNode;
void creatHuffmanTree(HTNode *ht, int n){
    int i,j;
    int lchild,rchild;
    int minL,minR;
    for(i = 0; i < 2*n - 1; i ++){
        ht[i].parent = ht[i].lchild = ht[i].rchild = -1;   //��Ϊ��û�б����ʹ��Ľ��
    }
    for(i = n; i < 2*n - 1; i ++){   //����С�ʹ�С��ֵ�㷨
        minL = minR = MAXNUMBER;
        lchild = rchild = -1;
        for(j = 0; j < i; j ++){
            if( ht[j].parent == -1 ) {
                if(ht[j].weight < minL){
                    minR = minL;
                    minL = ht[j].weight;
                    rchild = lchild;
                    lchild = j;
                }else if(ht[j].weight < minR){
                    minR = ht[j].weight;
                    rchild = j;
                }
            }
        }
        ht[lchild].parent = ht[rchild].parent = i;
		//printf("%d %d %d\n", lchild, rchild, i);
        ht[i].weight = minL + minR;
        ht[i].lchild = lchild;
        ht[i].rchild = rchild;
    }
}
typedef struct QHCode{
    char *code;
    int start;
}HCode;
void createHuffmanCode(HTNode *ht, HCode *hc, int n){
    int i,f,c;
    char *str;
    for(i = 0; i < n; i ++){
        int start = n;
        c = i;
        hc[i].code = (char *)malloc(sizeof(char)*n+1);
		str = (char *)malloc(sizeof(char)*n+1);
		str[n] = '\0';
        while( ( f = ht[c].parent ) != -1 ) {
            if( ht[f].lchild == c ) {
                str[--start] = '0';
            }
            else {
                str[--start] = '1';
            }
            c = f;
        }
		strcpy(hc[i].code, &str[start]);
    }
    free(str);
}
void displayHuffman(HTNode *ht, HCode *hc, int n)
{
	int i;
	for (i = 0; i < n; i ++){
		printf("%c(%d) %s\n", ht[i].c, ht[i].weight, hc[i]);
	}
}
int main(void)
{
    int n = 8, i;
    char str[]= {'A','B','C','D','E', 'F', 'G', 'H'}; /*�ַ���*/
    int fnum[]= {5, 29, 7, 8, 14, 23, 3, 11}; /*�ַ�����Ӧ��Ȩֵ*/
    HTNode *ht = (HTNode *)malloc(sizeof(HTNode)*(2*n-1));
    HCode *hcd = (HCode *)malloc(sizeof(HCode)*(2*n-1));
    for(i = 0; i < n; i++)
    {
		ht[i].c = str[i];
        ht[i].weight = fnum[i];
    }
    creatHuffmanTree(ht, n);
    createHuffmanCode(ht, hcd, n);
    displayHuffman(ht, hcd, n);
    printf("\n");
}
