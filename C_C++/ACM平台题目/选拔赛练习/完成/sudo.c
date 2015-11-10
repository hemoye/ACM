/*#include <stdio.h>
#include <string.h>

int main(void)
{
    char cmp1[3][100] = {"apt-get", "yum", "zypper"};
    char cmp2[3][100] = {"ubuntu", "fedora", "openSuse"};
    char ch[1001], str[1000][1001];
    int t, T;

    scanf("%d\n", &T);

    for (t = 1; t <= T; t++)
    {
        int i, j, num, flage = 1;

        gets(ch);

        for (i = num = j = 0; i < strlen(ch); i++)
            if (ch[i] == ' ')
            {
                str[num][j] = '\0';
                num++;
                j = 0;
            }
            else
                str[num][j++] = ch[i];
        str[num][j] = '\0';

        printf ("Case %d: ", t);

        if ((strcmp(str[2], "update") == 0 && num >= 3) || (strcmp(str[2], "upgrade") == 0 && num >= 3))
        {
            printf("invalid\n");
            continue;
        }

        for (i = 0 ; i < 3; i++)
            if (strcmp(cmp1[i], str[1]) == 0)
            {
                printf("valid %s\n", cmp2[i]);
                flage = 0;
                break;
            }
        if (flage)
            printf("invalid\n");
    }

    return 0;
}*/

#include <stdio.h>
#include <string.h>
int panduan(char *str)
{
    if(strcmp(str, "update")==0||strcmp(str, "upgrade")==0)
        return 1;
    else
        return 0;
}
int judge(char *str)
{
    if(strcmp(str, "apt-get")==0)
        return 1;
    else if(strcmp(str, "yum")==0)
        return 2;
    else if(strcmp(str, "zypper")==0)
        return 3;
    else
        return 0;
}
int main(void)
{
    char c[100], str[100][100];
    int T, j, t, k;
    int l=0;
    scanf("%d\n", &T);
    for(j=1; j<=T; j++)
    {
        int i=0, l=0;
        gets(c);
        for(k=0; c[k]!='\0'; k++)
        {
            if(c[k]!=' ')
                str[i][l++] = c[k];
            else
            {
                str[i][l] = '\0';
                i++;
                l=0;
            }
        }
        str[i][l] = '\0';
        printf("Case %d: ", j);
        if(i==2&&panduan(str[2])||i==3&&strcmp(str[2], "install")==0&&strcmp(str[3], "mysql-server")==0)
        {
            t = judge(str[1]);
            if(t==1)
                printf("valid ubuntu\n");
            else if(t==2)
                printf("valid fedora\n");
            else if(t==3)
                printf("valid openSuse\n");
            else
                printf("invalid\n");
        }
        else
            printf("invalid\n");
    }
    return 0;
}
