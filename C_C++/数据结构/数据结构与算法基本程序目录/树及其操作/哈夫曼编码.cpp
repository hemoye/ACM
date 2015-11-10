#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define  MAXN_SIZE 400
#define  INF 32727

struct HTNode {
    char c;          /**存储数据，可以是一个字符**/
    int weight;
    int parent;
    int left;
    int right;
} ;
struct HCode {
    char * code;
    int start;
} ;

void Creat_HuffmanTree( HTNode * , int );
void Creat_HuffmanCode( HTNode * , HCode * , int );
void Display_Huffman( HTNode * , HCode * , int );

int main( int agrc, char *agrv[] )
{
    int n = 8;
    char str[] = {"ABCDEFGH"};
    int fnum[] = { 5, 29, 7, 8, 14, 23, 3, 11 };

    HTNode * ht = new HTNode [2*n-1];
    HCode * hcd = new HCode [2*n-1];
    for ( int i = 0; i < n; i++ ){
        ht[i].c = str[i];
        ht[i].weight = fnum[i];
    }
    Creat_HuffmanTree( ht, n );
    Creat_HuffmanCode( ht, hcd, n );
    Display_Huffman( ht, hcd, n );
    puts("");

    return 0;
}
void Creat_HuffmanTree( HTNode * ht, int n )
{
    int lchild, rchild;
    int  minL, minR;

    for ( int i = 0; i < 2 * n - 1; i++ ){
        ht[i].left = ht[i].right = ht[i].parent = -1;
    }
    for ( int i = 0; i < n; i++ ){
        minL = minR = INF;
        lchild = rchild = -1;
        for ( int j = 0; j < i; j++ ){
            if ( -1 == ht[j].parent ){
                if ( ht[j].weight < minL ){
                    minR = minL;
                    minL = ht[i].weight;
                    rchild  = lchild;
                    lchild = j;
                }
                else if ( ht[j].weight < minR ){
                    minR = ht[j].weight;
                    rchild = j;
                }
            }
            ht[lchild].parent = ht[rchild].parent = i;
            ht[i].weight = minL + minR;
            ht[i].left = lchild;
            ht[i].right = rchild;
        }
    }
}
void Creat_HuffmanCode( HTNode * ht, HCode * hc, int n )
{
    int i, f, c;
    char * str;

    for ( i = 0; i < n; i++ ){
        int start = n;
        c = 1;
        hc[i].code = new char [n+1];
        str = new char [n+1];
        str[n] = '\0';
        while ( ( f = ht[c].left ) != -1 ){
            if ( ht[f].left == c ){
                str[--start] = '0';
            }
            else {
                str[--start] = '1';
            }
            c = f;
        }
        strcpy( hc[i].code, &str[start] );
    }
    free( str );
}
void Display_Huffman( HTNode * ht, HCode * hc, int n )
{
    int i;
    for ( i = 0; i < n; i++ ){
        printf("%c(%d) %s\n", ht[i].c, ht[i].weight, hc[i] );
    }
    return ;
}
