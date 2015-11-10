#include <iostream>
#include<stdio.h>
#define MAX 1000010
using namespace std;
struct node
{
 int left,right;
 int num;
 node()
 {
  num=0;
 }
};
node tree[4*MAX];
void build(int left,int right,int i)
{
 tree[i].left=left;tree[i].right=right;
 if (left<right)
 {
  int mid=(left+right)>>1;
  build(left,mid,2*i);
  build(mid+1,right,2*i+1);
 }
}
void insert(int i,int left,int right,int num)
{
 if(left<=tree[i].left&&tree[i].right<=right)
 {
  tree[i].num+=num;
  return;
 }
 if (tree[i].left<tree[i].right)
 {
  int mid=(tree[i].left+tree[i].right)>>1;
  if(right<=mid)
   insert(2*i,left,right,num);
  else if (left>mid)
   insert(2*i+1,left,right,num);
  else
  {
   insert(2*i,left,mid,num);
   insert(2*i+1,mid+1,right,num);
  }   
 }
}
int sum;
void finds(int k,int i)
{
 if (tree[i].left<=k&&k<=tree[i].right)
 {
  sum+=tree[i].num;
 }
 if(tree[i].left<tree[i].right)
 {
  int mid=(tree[i].left+tree[i].right)>>1;
  if(k<=mid)
   finds(k,2*i);
  else 
   finds(k,2*i+1);  
 }
}
int main()
{
 int n,t,k,i,num,left,right;
 char a[10];
 cin>>t>>n;
 build(1,n,1);
 for(i=0;i<t;i++)
 {
  scanf("%s",a);
  if(a[0]=='A')
  {
   scanf("%d%d%d",&left,&right,&num);
   insert(1,left,right,num);
  }
  else
  {
   sum=0;
   scanf("%d",&k);
   finds(k,1);
   printf("%d\n",sum);
  }  
 }
 return 0;
}