#include<stdio.h>
#include<string.h>

int main(void)
{
    int T,k,i,j,sum;
    k = 1;
    char str[100];
    scanf("%d",&T);
    while (T--)
    {
        sum = 0;
        scanf("%s",str);
        if (str[0]!='p')
        {
            if (str[0]=='f')
                sum = 1024;
        }
        else
        {
            for (i = 1; str[i]!='\0'; i++)
            {
                if (str[i]=='p')
                {
                    j = i;
                    for (i = i+1;  i <= j+4; i++)
                        if (str[i]=='f')
                            sum += 64;
                    i--;
                }
                else
                    if (str[i]=='f')
                        sum += 256;
            }
        }
        printf("Case %d:\n",k++);
        printf("There are %d black pixels.\n",sum);

    }
    return 0;
}
/*
        北京时间2012年9月13日凌晨，苹果公司在美国旧金山芳 草地艺术中心举行新品发布会，正式发布其新一代产品 iPhone 5。新产品屏幕更大，同时也变得更轻薄。iPhone 5采用4英寸视网膜屏，屏幕分辨率由原来的960x640升级为1136x640，同时主屏幕中的应用图标增加至5排。iPhone 5 预装最新的 iOS 6 手机操作系统。目前已于2012年9月21日上市，比官方发售日期提前2天。而中国香港成为首批上市的地区之一。



      小胖子的山寨机前不久忘在教室，然后。。。不见了。。（和我一样。。悲剧啊），所以最近小胖子准备买一部手机，正逢iphone5上市，外观和性能那是相当强悍啊！！小胖子看得口水都流出来了，可惜钱不够啊，无奈只能退而求其次，换了个小米。。。。但是小胖子又觉得这样不合适，只好编一个理由了----屏幕漏光。。有坏点。。。然后小胖子就写了个程序，检查屏幕的坏点数量

     已知屏幕总共有1024个像素，因为我们要求坏点个数，所以要将像素细分。。用p来细分像素，每一次把屏幕分成4块区域（如下图），每块区域的像素为总区域像素的 1 / 4 ，如果还不能判断，则继续细分。当然，如果这块区域都是坏点，那么就不用细分，我们用 f 来表示区域是个坏点，用 e 来表示区域不是坏点，求出坏点的数量（坏点的用字母来表示如下图，解释见输入）



Input

输入第一个数n，表示有几组数据，接下来输入n组，每组一行字符串，代表测试的结果。

每行字符串包括 p, e, f 3种字符，当输入p时，表示将区域细分，接下来是细分的第一个区域，如果还是p，则继续细分，如果是e，表示该区域不是坏点，如果是f，表示该区域是坏点，以此类推。

例如ppeeefpffeefe，

ppeeef

首先输入的是p，然后将1024分为4个区域，每个区域256，接下来输入的还是p，然后将第一个256再分成4个区域，每个64，连续的3个e表示前3个64不是坏点，然后一个f表示第4个64是坏点，此时，第一个256测试完毕， 坏点为64个

pffee

然后输入的又是一个p，将第二的256分为4份，计算同上，坏点有128个

f

然后输入的是一个f，表示该256全是坏点

e

然后是一个e，表示该256全不是坏点

最后总坏点数为 64 + 128 + 256 = 448 个

为了让题目简单点，题目保证最大只分到64像素，不会继续往下分。

测试数据保证输入的规范。

Output

每个输出以一个Case i: 开始，然后计算测试后得到的坏点数总和sum，

输出 “There are sum black pixels.”

Sample Input

5
ppeeefpffeefe
pefepeefe
ppeeefffpeefe
peeef
f
Sample Output

Case 1:
There are 448 black pixels.
Case 2:
There are 320 black pixels.
Case 3:
There are 640 black pixels.
Case 4:
There are 256 black pixels.
Case 5:
There are 1024 black pixels.
*/
