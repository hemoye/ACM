#include <cstdio>
#include <string>
#include <set>

using namespace std;

set<string> str;

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);
	str.insert("fork");
	str.insert("chopsticks");
	str.insert("knife");
	str.insert("bowl");

	int n;
	char sex[20];

	while (~scanf("%d", &n)){
		int count(0);
		while (n--){
			scanf("%s", sex);
			if (str.count(sex)){
				printf(count ? " %s" : "%s", sex);
				count++;
			}
		}
		puts("");
	}

	return 0;
}