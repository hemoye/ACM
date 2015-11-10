#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

const int MAXN = 1000;

using namespace std;

void sub(string s1, string s2, char *t)
{
    int len1 = s1.length();
    int len2 = s2.length();
    int i = len1 - 1, j = len2 - 1;
    int flage = 0;

    while (j >= 0){
        int temp = s1[i] - s2[j] + flage;
        if (temp >= 0)  flage = 0;
        else {
            temp += 10;
            flage = -1;
        }
        t[i] = temp + '0';
        i--;
        j--;
    }
    while (i >= 0){
        t[i] = s1[i] + flage;
        flage = 0;
        i--;
    }

    return ;
}

int main(int agrc, char *agrv[])
{
    string str1, str2;

    while (cin >> str1 >> str2){
        char str[MAXN];
        if ( str1 < str2 ){
            string str3 = str1;
            str1 = str2;
            str2 = str3;
            printf("-");
        }
        sub(str1, str2, str);
        puts(str);
    }

    return 0;
}
