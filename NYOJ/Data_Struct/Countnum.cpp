#include <cstdio>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	freopen("test.in", "r", stdin);
	int n;
	string str;

	while (~scanf("%d", &n)){
		set<string> s;
		for (int i = 0; i < n; i++){
			cin >> str;
			s.insert(str);
		}
		int max(0), pos(0);
/*		for (int i = 0; i < s.size(); i++){
			if (s.count(i) > max){
				max = s.count(i);
				pos = i;
			}
		}*/
		int count = s.count("sheep");
		cout << *s.find(str) << count << endl;
	}

	return 0;
}
