#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node {
	struct Node * Next[10];
	bool flag;
} ;

Node * root;

Node * Create()
{
	Node * p = new Node;
	p->flag = false;
	for (int i = 0; i < 10; i++) p->Next[i] = NULL;
	return p;
}
bool insert(char *s)
{
	Node *p = root;
	int len = strlen(s);
	for (int i = 0; i < len; i++){
		if (p->Next[s[i]-'0'] == NULL){
			p->Next[s[i]-'0'] = Create();
			p = p->Next[s[i]-'0'];
			if (i == len - 1) p->flag = true;
		}
		else {
			if (p->Next[s[i]-'0']->flag || i == len - 1) return true;
			p = p->Next[s[i]-'0'];
		}
	}
	return false;

int main(int argc, char const *argv[])
{
	/*freopen("test.in", "r", stdin);*/
	int t, n;
	char str[12];

	scanf("%d", &t);
	while (t--){
		bool result(true);
		root = Create();
		scanf("%d", &n);
		while (n--)	{
			scanf("%s", str);
			if (result && insert(str)) result = false;
		}
		if (result) puts("YES");
		else puts("NO");
	}

	return 0;
}	
