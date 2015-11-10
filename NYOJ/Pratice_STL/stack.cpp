#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

const int MAXN = 10004;

int main(int argc, char const *argv[])
{
	/*freopen("test.in","r", stdin);*/
	int n;
	char str[MAXN];

	scanf("%d", &n);
	while (n--){
		stack<char> s;
		scanf("%s", str);
		int k, len = strlen(str);
		for (k = 0; k < len; k++){
			if (str[k] == '[' || str[k] == '(') s.push(str[k]);
			else if (!s.empty() && str[k] == ']' && s.top() == '[') s.pop();
			else if (!s.empty() && str[k] == ')' && s.top() == '(') s.pop();
			else break;
		}
		if (k == len && s.empty()) puts("Yes");
		else puts("No");
	}

	return 0;
}	