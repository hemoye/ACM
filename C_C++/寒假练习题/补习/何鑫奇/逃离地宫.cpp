#include<iostream>
#include<queue>
#include<memory.h>
using namespace std;
int row,col;
int map[8][8],mark[8][8];
struct node
{
    int x,y;
    int t_use;
    int t_remain;
} start;
void store_map()
{
    int i,j;
    for(i=0; i<row; i++)
        for(j=0; j<col; j++)
        {
            cin>>map[i][j];
            if(map[i][j]==2)
            {
                start.x=i;
                start.y=j;
                start.t_use=0;
                start.t_remain=6;
            }
        }
}
void BFS()
{
    const int help[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
    queue<node> myqueue;
    myqueue.push(start);
    memset(mark,0,sizeof(mark));
    mark[start.x][start.y]=6;
    bool flag=0;
    int t_use=0,t_remain=0;
    while(!myqueue.empty() && !flag)
    {
        node tmp=myqueue.front();
        myqueue.pop();
        int i;
        for(i=0; i<4; i++)
        {
            if(flag)
                break;
            node temp;
            temp.x=tmp.x+help[i][0];
            temp.y=tmp.y+help[i][1];
            if(map[temp.x][temp.y]==0 || temp.x<0 || temp.x>=row || temp.y<0 || temp.y>=col)
                continue;
            temp.t_use=tmp.t_use+1;
            temp.t_remain=tmp.t_remain-1;
            if(map[temp.x][temp.y]==4)
                temp.t_remain=6;
            else if(map[temp.x][temp.y]==3)
            {
                flag=1;
                t_remain=temp.t_remain;
                t_use=temp.t_use;
            }
            if(temp.t_remain>1 && temp.t_remain>mark[temp.x][temp.y])   //满足条件则入队列
            {
                mark[temp.x][temp.y]=temp.t_remain;
                myqueue.push(temp);
            }
        }
    }
    if(flag && t_remain>0)
        cout<<t_use<<endl;
    else
        cout<<"-1"<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>row>>col;
        store_map();
        BFS();
    }
    return 0;
}
