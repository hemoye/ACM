#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int father[10006];
int num[10006];
int b[10006];
vector<int> a[10006];
void Init()
{
memset(num,0,sizeof(num));
for(int i=0;i<10006;++i)
father[i]=i;
}
int findfather(int i)
{
for(i;i!=father[i];i=father[i]) ;
return father[i];
}
void Union(int a,int b)
{
if(findfather(a)==findfather(b)) return;
else
{
int x=findfather(a);
int y=findfather(b);
if(num[x]>num[y])
{
father[y]=x;
num[x]+=num[y];
}
else
{
father[x]=y;
num[y]+=num[x];
}
}
}
int main()
{
int row,col,flag,flag2,n,i,j,Count=0;
while(1)
{
flag2=1;
flag=1;
n=0;
Init();
memset(a,0,sizeof(a));
memset(b,0,sizeof(b));
while(scanf("%d%d",&row,&col))
{
if(row==0&&col==0) break;
if(row==-1&&col==-1) { flag2=0;break;}
b[n++]=col;
a[col].push_back(row);
if(findfather(row)==findfather(col)) flag=0; //加这一步就ok了，
Union(row,col);
}
int fat=findfather(b[0]),temp;
for(i=0;i<n;++i)
{
temp=b[i];
for(j=0;j<a[temp].size();++j)
{
if(findfather(a[temp][j])!=fat)
{
flag=0;
break;
}
if(a[temp].size()>1)
{
flag=0;
break;
}
}
}
if(!flag2) break;
Count++;
if(flag)
cout<<"Case "<<Count<<" is a tree."<<endl;
else
cout<<"Case "<<Count<<" is not a tree."<<endl;
}
}