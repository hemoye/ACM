#include <iostream>  
#include <cstdio>  
#include <algorithm>  
#include <string.h>  
#include <string>  
#include <vector>  
using namespace std;  
vector<int> aa[10005];  
int main(){  
  int kk;  
  scanf("%d",&kk);  
  memset(aa,0,sizeof(aa));  
  int n,x,j;  
  char ss[7];  
  while(kk--){  
    scanf("%s",ss);  
    scanf("%d",&n);  
    if(ss[0]=='A'){  
        while(n--){  
          scanf("%d",&x);  
          int y=x%10001;  
          aa[y].push_back(x);  
        }  
    }  
    else{  
        while(n--){  
          scanf("%d",&x);  
          int len=aa[x%10001].size();  
          for(j=0;j<len;++j){  
             if(x==aa[x%10001][j])  
             {  
               printf("YES\n");  
               break;  
             }  
        }  
         if(j==len)  
              printf("NO\n");  
    }  
  }  
  }  
  return 0;  
}  