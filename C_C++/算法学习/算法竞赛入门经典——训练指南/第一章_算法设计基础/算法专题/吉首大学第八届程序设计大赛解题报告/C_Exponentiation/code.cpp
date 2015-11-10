#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
 
#define MAXSPLIT        10
#define MAXVAL          27
#define MAXN            101
 
char split[MAXN][MAXSPLIT];
int val_table[MAXVAL], mark[MAXVAL], pos, idx;
 
void non_space(char *str)
{
        char tmp[MAXN];
        idx = 0;
        for(int i = 0; i < MAXVAL; i ++) {
                val_table[i] = i+1;
        }
        for(int i = 0; i < strlen(str); i ++) {
                if( ' ' == str[i] ) {
                        continue;
                }
                tmp[idx ++] = str[i];
        }
        tmp[idx] = '\0'; strcpy(str, tmp);
}
 
void split_var(const char *str)
{
        pos = 0;
        for(int i = 0; i < strlen(str); i ++) {
                if( !isalpha(str[i]) ) {
                        continue;
                }
                if( i >= 2 && (str[i-1] == str[i-2]) && ('+' == str[i-1] || '-' == str[i-1]) ) {
                        idx = 0;
                        for(int k = i-2; k <= i; k ++, idx ++) {
                                split[pos][idx] = str[k];
                        }
                        split[pos ++][idx ++] = '\0';
 
                        if( i+1 < strlen(str) ) {
                                split[pos][0] = str[i+1]; split[pos ++][idx ++] = '\0';
                        }
                         continue;
                }
                if( i+2 < strlen(str) && (str[i+1] == str[i+2]) && ('+' == str[i+1] || '-' == str[i+1]) ) {
                        idx = 0;
                        for(int k = i; k <= i+2; k ++, idx ++) {
                                split[pos][idx] = str[k];
                        }       
                        split[pos ++][idx ++] = '\0';
 
                        if( i+3 < strlen(str) ) {
                                split[pos][0] = str[i+3]; split[pos ++][idx ++] = '\0';
                        }
                        continue;
                }
                split[pos][0] = str[i]; split[pos ++][1] = '\0';
                if( i+1 < strlen(str) ) {
                        split[pos][0] = str[i+1]; split[pos ++][1] = '\0';
                }
        }
}
 
int get_expression(const int &index)
{
        int rst;
        if( strlen(split[index]) > 1 && isalpha(split[index][0]) ) {
                rst = val_table[ split[index][0]-'a' ];
                val_table[ split[index][0]-'a' ] = ('+' == split[index][1])? rst+1 : rst-1;
        }
        if( strlen(split[index]) > 1 && !isalpha(split[index][0]) ) {
                rst = val_table[ split[index][2]-'a' ];
                rst = val_table[ split[index][2]-'a' ] = ('+' == split[index][1])? rst+1 : rst-1;
        }
        else if( 1 == strlen(split[index]) ) {
                rst = val_table[ split[index][0]-'a' ];
        }
        return rst;
}
 
int expression_ans(void)
{
        int ans(get_expression(0)), l_val, r_val;
        for(idx = 1; idx < pos; idx += 2) {
                r_val = get_expression(idx+1);
                ans = ('+' == split[idx][0])? ans+r_val : ans-r_val;
        }
        return ans;
}
 
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
        freopen("test.in", "r", stdin);
#endif
        char str[MAXN];
        while( gets(str) > 0 ) {
                printf("Expression: %s\n", str);
                non_space(str); split_var(str);
                printf("    value = %d\n", expression_ans());
                memset(mark, 0, sizeof(mark));
                for(int i = 0; i < strlen(str); i ++) {
                        if( isalpha(str[i]) ) {
                                mark[str[i]-'a'] = 1;
                        }
                }
                for(int i = 0; i < MAXVAL; i ++) {
                        if( mark[i] ) {
                                printf("    %c = %d\n", i+'a', val_table[i]);
                        }
                }
        }
        return 0;
}
/**************************************************************
    Problem: 5323
    User: 周公瑾
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:960 kb
****************************************************************/
