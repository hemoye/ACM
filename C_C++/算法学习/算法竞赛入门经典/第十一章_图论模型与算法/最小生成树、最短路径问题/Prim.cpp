#include <iostream>
using namespace std;
//���ڽӾ����ʾ����ͼ
#define N 6 //�ڵ����
#define M 100000//���ֵ����ʾ���ɴ�
int matrix[N][N]=
{
    M,6,1,5,M,M,
    6,M,5,M,3,M,
    1,5,M,5,6,4,
    5,M,5,M,M,2,
    M,3,6,M,M,6,
    M,M,4,2,6,M
};
void prim()
{
    bool flag[N]; //���ĳ�����Ƿ�ǰ������������
    int i,j;
//��ʼ������
    for(i = 0; i < N; ++i) flag[i] = false;
    flag[0] = true;
    int count = 1;
    while(count++ < N)
    {
        int min = M;
        int e1 = -1, e2 = -1;
        for(i = 0; i < N; ++i)
        {
            if(flag[i])
            {
                for(j = 0; j < N; ++j)
                {
                    if(!flag[j])
                    {
                        if(matrix[i][j] < min)
                        {
                            min = matrix[i][j];
                            e1 = i;
                            e2 = j;
                        }
                    }
                }
            }
        }
        cout<<e1 + 1<<"-"<<e2 + 1<<" "<<matrix[e1][e2]<<endl;
        flag[e2] = true;
    }
}
int main( int argc, char *argv[] )
{
    prim();
    return 0;
}
