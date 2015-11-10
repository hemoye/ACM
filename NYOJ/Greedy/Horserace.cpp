#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1004;

bool CMP(int x, int y)
{
	return x > y;
}

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);
	int n;
	int Tian[MAXN], King[MAXN];

	while (~scanf("%d", &n)){
		for (int i = 0; i < n; i++) scanf("%d", Tian + i);
		for (int i = 0; i < n; i++)	scanf("%d", King + i);
		sort(Tian, Tian + n, CMP);
		sort(King, King + n, CMP);
		int win(0), fail(0);  
        int tj = n-1, qw = n-1;  
        for (int i = 0, j = 0; i <= tj; ){  
            if (Tian[i]>King[j]){
            	win++;
            	i++;
            	j++;
            }  
            else {  
                if(Tian[tj] > King[qw]){
                	win++; 
                	tj--; 
                	qw--;
                }  
                else{  
                    if (Tian[tj] < King[j]){
                    	fail++; 
                    	tj--; 
                    	j++;
                    }  
                    else{
                    	i++; 
                    	j++;
                    }  
                }  
            }  
        }  
        printf("%d\n", 200*(win-fail));  
	}

	return 0;
}