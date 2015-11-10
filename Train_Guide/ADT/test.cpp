#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

/*
    最大间隙问题：(要求使用线性阶的时间复杂度)
    需要运用的是鸽巢原理(抽屉原理)
        在本题目中，要处理的数据一共有n个。
        选取到最大值以及最小值之后，就代表已经取得了鸽巢的总区间为[Min, Max]。
        此时利用鸽巢原理，在(Min, Max)之间划分出n-1个区间(即鸽巢)，放入n-1个数字，
        所以、势必会有一个鸽巢是空的。
        从而、最大的间隙就是空鸽巢的上一个鸽巢中的最大值与下一个鸽巢中的最小值之差。
        于是、可以取得最优解。
        但是，需要注意的是：倘若空鸽巢是最小值右边的第一个鸽巢时或者是最大值左边的
        第一个鸽巢时，其最优解就是第二个鸽巢的最小值(最大值)与Min(Max)之差。
*/

using namespace std;
const int MAXN = 1024;
const int INF = 0x7ffff;
vector<int> v[MAXN];
float arrAy[MAXN];

float findMin(int x)
{
    int t = v[x].size();
    float Min(INF);
    for (int i = 0; i < t; i++){
        if (Min > arrAy[v[x][i]]){
            Min = arrAy[v[x][i]];
        }
    }
    return Min;
}
float findMAX(int x)
{
    int t = v[x].size();
    float Max(-INF);
    for (int i = 0; i < t; i++){
        if (Max < arrAy[v[x][i]]){
            Max = arrAy[v[x][i]];
        }
    }
    return Max;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
#endif
    int n;
    
    while (~scanf("%d", &n)){
        float MAX(-INF), MIN(INF);
        float ans(0);
        for (int i = 0; i < n; i++){                    //读入数据并找出最大值与最小值
            scanf("%f", arrAy + i);
            if (MAX < arrAy[i]) MAX = arrAy[i];
            if (MIN > arrAy[i]) MIN = arrAy[i];
        }
        float d = (MAX - MIN) / (n - 1);                //求得鸽巢(抽屉)的宽度，即等差数列的公差
        for (int i = 0; i < n; i++){
            int index(0);
            if (arrAy[i] < MAX && arrAy[i] > MIN){
                index = (arrAy[i] - MIN) / d;
                v[index].push_back(i);
            }
        }
        int pos(0);
        for (int i = 0; i < n - 1; i++){                //找出空出来的那个抽屉
            if (!v[i].size()){
                pos = i;
                break;
            }
        }
        if (pos == 0){
            float t = findMin(pos+1);
            ans = t - MIN;
        }
        else if (pos == n - 1){
            float t = findMAX(pos-1);
            ans = MAX - t;
        }
        else {
            float tmin = findMin(pos-1);
            float tmax = findMAX(pos+1);
            ans = tmax - tmin;
        }
        printf("%f\n", ans);
    }

    return 0;
}
