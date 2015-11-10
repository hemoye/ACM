#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
map<int, vector<int> > v;

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	int m, n, x, y;

	while (~scanf("%d%d", &n, &m)){
		v.clear();
		for (int i = 0; i < n; i++){
			scanf("%d", &x);
			if (!v.count(x)) v[x] = vector<int>();
			v[x].push_back(i+1);
		}
		while (m--){
			scanf("%d%d", &x, &y);
			if (!v.count(y) || v[y].size() < x) puts("0");
			else printf("%d\n", v[y][x-1]);
		}
	}

	return 0;
}
/*
问题描述：
	给出一个包含n个整数的数组，你需要回答若干个询问。每次询问两个整数k和v，输出从左到右第k个v的下标（数组下标从左到右编号为1~n）
输入格式
	输入包含多组数据。每组数据第一行为李娜改革整数n和m（0<n,m<100001），第二行包含n个不超过10^6的正整数，即待查询的数组
	以下m行每行包含两个整数k和v。输入结束的标志为文件结束符。输入文件不超过5MB
输出格式
	对于每个查询，输出查询结果。如果不存在，输出0
*/
