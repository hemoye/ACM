#include<stdio.h>
#include<malloc.h>
#define MAX 1000
int c[1000];

int cmp ( const void *a , const void *b)
{
    return *(int *)a - *(int *)b;
}

typedef struct Node
{
    int data[MAX];
    int lengh;
}*node;

void Init(node);
// void traverse(node);
void sort(node, int);

int main()
{
	freopen("test.in", "r", stdin);

    int * phead;
    int k;
    node s = (node)malloc(sizeof(struct Node));
    scanf("%d", &s->lengh);
    Init(s);
    scanf("%d", &k);
    sort(s,k);
//    traverse(s);
    return 0;
}

void Init(node p)
{
    int i;
    for(i = 0; i < p->lengh; i ++)
        scanf("%d", &p->data[i]);
//    scanf("%d", &p->data[p->lengh]);
//     for(i = 0; i < p->lengh; i ++)
//    printf("%d ", p->data[i]);
    return ;
}

void sort(node s,int k)
{
    int leng = s->lengh;
    int i,j,l = 0;
    qsort(s->data, s->lengh, sizeof(s->data[0]),cmp);
//   i = lengh - 1;
    for(i = 0; i < s->lengh; i ++)
        printf("%d ", s->data[i]);
    i = leng - 1;
    while(s->data[i] > k)
    {
        i--;
    }

    for(j = i; j < s->lengh; j ++)
    {
        c[s->data[j]] = 1;
    }

    for(j = i; j <s->data[leng - 1]; j++ )
    {
        if(c[j] != 0)
            l++;
    }
    printf("====%d\n", l);
    i = 0;
    while(s->data[i] < k)
    {
        i++;
    }
    for(j = 0; j <= i; j ++)
    {
        printf("%d ",s->data[j]);
    }
    puts("");

    return;
}
