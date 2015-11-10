#include <cstdio>
#include <cstdlib>

char ing[1004];

double jisuan(bool p=true)
{
	if(p) scanf("%s",ing);
	if(ing[0]=='+') return jisuan()+jisuan();
	else if(ing[0]=='*') return jisuan()*jisuan();
	else if(ing[0]=='-') return jisuan()-jisuan();
	else if(ing[0]=='/') return jisuan()/jisuan();
	else return atof(ing);
}
int main()
{ 
	/*freopen("test.in", "r", stdin);*/
	while(scanf("%s",ing)!=EOF) {
		printf("%.2lf\n",jisuan(false));
	}

	return 0;
}