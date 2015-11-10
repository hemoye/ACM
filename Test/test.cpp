#include <cstdio>
#include <cstring>

#define itemName "FTALerts__devIddevIdddd_"
#define paramName "devId"

int main(void)
{
    char start[5]="__";     //开始位置标识
    //提取数字部分
    char *params = strstr(itemName,start) + 2;
    char *sp = strstr(params,paramName)+strlen(paramName);
    char *ep = strchr(sp,'_');
    int size = ep -sp;
    printf("%s\n",params);
    printf("%s\n",sp);
    printf("%s\n",ep);
    printf("%d\n", size);

    return 0;
}