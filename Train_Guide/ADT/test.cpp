#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

/*
    ����϶���⣺(Ҫ��ʹ�����Խ׵�ʱ�临�Ӷ�)
    ��Ҫ���õ��Ǹ볲ԭ��(����ԭ��)
        �ڱ���Ŀ�У�Ҫ���������һ����n����
        ѡȡ�����ֵ�Լ���Сֵ֮�󣬾ʹ����Ѿ�ȡ���˸볲��������Ϊ[Min, Max]��
        ��ʱ���ø볲ԭ����(Min, Max)֮�仮�ֳ�n-1������(���볲)������n-1�����֣�
        ���ԡ��Ʊػ���һ���볲�ǿյġ�
        �Ӷ������ļ�϶���ǿո볲����һ���볲�е����ֵ����һ���볲�е���Сֵ֮�
        ���ǡ�����ȡ�����Ž⡣
        ���ǣ���Ҫע����ǣ������ո볲����Сֵ�ұߵĵ�һ���볲ʱ���������ֵ��ߵ�
        ��һ���볲ʱ�������Ž���ǵڶ����볲����Сֵ(���ֵ)��Min(Max)֮�
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
        for (int i = 0; i < n; i++){                    //�������ݲ��ҳ����ֵ����Сֵ
            scanf("%f", arrAy + i);
            if (MAX < arrAy[i]) MAX = arrAy[i];
            if (MIN > arrAy[i]) MIN = arrAy[i];
        }
        float d = (MAX - MIN) / (n - 1);                //��ø볲(����)�Ŀ�ȣ����Ȳ����еĹ���
        for (int i = 0; i < n; i++){
            int index(0);
            if (arrAy[i] < MAX && arrAy[i] > MIN){
                index = (arrAy[i] - MIN) / d;
                v[index].push_back(i);
            }
        }
        int pos(0);
        for (int i = 0; i < n - 1; i++){                //�ҳ��ճ������Ǹ�����
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
