#include <cstdio>
#include <stack>
#include <cstring>
#include <cstdlib>

using namespace std;
const int MAXN = 1004;

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);
	stack<char> sc;
	stack<float> sf;

	int n;
	char tes[MAXN];
	char str[MAXN];

	scanf("%d", &n);
	while (n--){
		while (!sc.empty()) sc.pop();
		while (!sf.empty()) sf.pop();
		scanf("%s", str);
		int k(0);
		int len = strlen(str);
		for (int i = 0; i < len; i++){
			if ('+' == str[i] || '-' == str[i] || '\\' == str[i] || '*' == str[i] || '(' == str[i]){
				tes[k] = '\0';
				k = 0;
				sf.push(atof(tes));
				sc.push(str[i]);
			}
			else if (')' == str[i]){
				tes[k] = '\0';
				k = 0;
				sf.push(atof(tes));
				while (sc.top() != '('){
					float temp = sf.top();
					sf.pop();
					if (sc.top() == '+') sf.top() += temp;
					else if (sc.top() == '-') sf.top() = temp - sf.top();
					else if (sc.top() == '*') sf.top() *= temp;
					else sf.top() = temp / sf.top();
					sc.pop();
				}
				sc.pop();
			}
			else if (str[i] == '=') break;
			else tes[k++] = str[i];
		}
		printf("%.2lf\n", sf.top());
	}

	return 0;
}	