#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAXN = 1004;

using namespace std;

void m_of_n(int low, int len, int *arrAy)
{
    if (low == len - 1){
        for (int i = 0; i < len; i++)  printf("%d", arrAy[i]);
        puts("");
    }
    else {
        for (int i = low; i < len; i++){
            swap(arrAy[low], arrAy[i]);
            m_of_n(low+1, len, arrAy);
            swap(arrAy[low], arrAy[i]);
        }
    }
}

int main(int agrc, char *agrv[])
{
    int n;
    int arrAy[MAXN];

    while (~scanf("%d", &n)){
        for (int i = 0; i < n; i++) scanf("%d", arrAy + i);
        m_of_n(0, n, arrAy);
    }

    return 0;
}
