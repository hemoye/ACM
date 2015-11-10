#include <iostream>  
#include <cstring>  
#include <string>  
#include <algorithm>  
#include <cstdio>  
  
using namespace std;  
  
#define MAXN 2100  
  
char str[MAXN];  
int n;  
  
void func()  
{  
    int cnt=0,l=0,r=n-1;  
    while(l<=r)
    {  
        bool lf=1;  
        for(int i=0;i+l<=r;i++)  
        {  
            if(str[l+i]<str[r-i])  
            {  
                lf=1;  
                break;  
            }  
            else if(str[l+i]>str[r-i])  
            {  
                lf=0;  
                break;  
            }  
        }  
  
        if(lf)  
            putchar(str[l++]);  
        else  
            putchar(str[r--]);  
        cnt++;  
        if(cnt==80)  
        {  
             printf("\n");  
             cnt=0;  
        }  
    }  
    printf("\n");  
}  
  
int main()  
{  
    while(cin>>n)  
    {  
        for(int i=0;i<n;i++) cin>>str[i];  
        str[n]='\0';  
        func();  
    }  
    return 0;  
}  