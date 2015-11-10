#include <stdio.h>
#include <math.h>
int main(void)
{
    float judge_1(float x);//函数声明
    float judge_2(float x);

    float a, b, c, x1, x2, detal;//变量声明

    scanf("%f %f %f", &a, &b, &c);//输入一元二次方程的各个系数
    detal = b * b - 4 * a * c;//求一元二次方程判别式的值
    if (detal >= 0)//如果判别式大于0则调用judge_1
    {
        x1 = (-b + judge_1(detal)) / (2 * a);
        x2 = (-b - judge_1(detal)) / (2 * a);
        printf("%.2f %.2f\n", x1, x2);
    }
    else//否则调用judge_2
    {
        x1 = (-b) / (2 * a);
        x2 = judge_2(detal) / (2 * a);
        printf("%.2f+%.2fi %.2f-%.2fi\n", x1, x2, x1, x2);
    }

    return 0;
}
float judge_1(float x)
{
    x = sqrt(x);

    return x;
}
float judge_2(float x)
{
    x = sqrt(-x);

    return x;
}
