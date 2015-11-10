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
//�ǵ�ǰ�������Ľڵ㼯��ΪS
//δʹ�õĽڵ���ΪV
    bool flag[N]; //���ĳ�����Ƿ���S��
    int nearest[N]; //��¼V��ÿ���㵽S���ڽӵ����̱�
    int adjecent[N];//��¼��V��ÿ�������ڽӽ��ĵ�
    int i,j,min;
//��ʼ������
    for(i = 0; i < N; ++i) flag[i] = false;
    flag[0] = true;
    for(i = 1; i < N; ++i)
    {
        nearest[i] = matrix[0][i];
        adjecent[i] = 0;
    }
    int count = N;
    while(--count)
    {
        min = M;
        j = 0;
        for(i = 0; i < N; ++i)
        {
            if(!flag[i] && nearest[i] < min)
            {
                min = nearest[i];
                j = i;
            }
        }
        cout<<j + 1<<"-"<<adjecent[j] + 1<<" "<<matrix[j][adjecent[j]]<<endl;
        flag[j] = true;
        for(i = 0; i < N; ++i)
        {
            if(!flag[i] && matrix[i][j] < nearest[i])
            {
                nearest[i] = matrix[i][j];
                adjecent[i] = j;
            }
        }
    }
}
int main(int argc, char* *argv)
{
    prim();
    return 0;
}
