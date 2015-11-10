#include "stdio.h"
int main(void)
{
     int act[11][3]={{1,1,4},{2,3,5},{3,0,6},{4,5,7},{6,5,9},
      {7,6,10},{8,8,11},{9,8,12},{10,2,13},{11,12,14}};
     greedy(act,11);
     getch();

     return 0;
}
int greedy(int *act,int n)
{
     int i,j,no;
      j=0;
     printf("Selected activities:/n");
     no=0;
     printf("Act.%2d: Start time %3d, finish time %3d/n",  act[no],act[no+1],act[no+2]);
    for(i=1;i<n;i++)
    {
        no=i*3;
        if(act[no+1]>=act[j*3+2])
             {
                 j=i;
                 printf("Act.%2d: Start time %3d, finish time %3d/n",        act[no],act[no+1],act[no+2]);
             }
       }
 }
/*贪心算法
所谓贪心算法是指，在对问题求解时，总是做出在当前看来是最好的选择。也就是说，不从整体最优上加以考虑，他所做出的仅是在某种意义上的局部最优解。
贪心算法不是对所有问题都能得到整体最优解，但对范围相当广泛的许多问题他能产生整体最优解或者是整体最优解的近似解。贪心算法的基本思路如下：
1.建立数学模型来描述问题。
2.把求解的问题分成若干个子问题。
3.对每一子问题求解，得到子问题的局部最优解。
4.把子问题的解局部最优解合成原来解问题的一个解。
*/
