#include <stdio.h>

int main(void)
{
    void Exchange(int * a, int * b);//��������

    int first, last, index, sum;//�������

    scanf("%d", &sum);//����������ݵ�����

    for (index = 1; index <= sum; index++)
    {
        scanf("%d %d", &first, &last);//�����������
        Exchange(&first, &last);//���ú���

        printf("Case %d: %d %d\n", index, first, last);//����������ֵ
    }

    return 0;
}
void Exchange(int * a, int * b)//���庯��
//���ܣ���ָ�뻥���������α�����ֵ
{
    int temp;

    temp = *a;//a����ָ�������a����ľ���frist�ĵ�ַ��*a�ȼ���first��ֵ
    *a = *b;
    *b = temp;
}
/*
�ܽ᣺1��ָ����ǵ�ַ����ַ����ָ��
      2����ַ�����ڴ浥λ�ı��
      3��ָ��������д�ŵ�ַ�ı���
      4��ָ���ָ�������������ͬ�ĸ���
      5������Ҫע�⣬ͨ����������ʱ���ָ��������ָ��
         ʵ�������ǲ�һ��
*/
