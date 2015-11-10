#include <cstdio>
#include <cstring>
#include <algorithm>

using naemspace std;

struct Item {
	int QNum;
	int Period;
	int Time;
	bool operator < (const Item& a) const {
		return Time > a.Time || (Time == a.Time && QNum > a.QNum);
	}
} ;

int main(int argc, char const *argv[])
{
	priority_queue<Item> pq;
	char str[20];

	while (~scanf("%s", str)){
		if (str[0] == '#') break;
		Item item;
		scanf("%d%d", &item.QNum, &item.Period);
		item.Time = item.Period;
		pq.push(item);
	}
	int K;
	scanf("%d", &K);
	while (K--){
		Item r = pq.top();
		pq.pop();
		printf("%d\n", r.QNum);
		r.Time += r.Period;
		pq.push(r);
	}

	return 0;
}

/*
	题目描述：
		你的任务是编写一个成为Argus的系统。该系统支持一个Register命令
				Register Q_num Period
		该命令注册了一个触发器，它每Period秒钟就会产生一次编号为Q_num的事件
		你的任务是模拟出前K个事件。如果多个时间同时发生，先处理Q_num小的事件
	输入格式：
		输入仅仅包含一组数据。前若干行是Register命令，以“#”结尾；最后一行是
		整数k。对于每条命令，1<=Q_num，Period<=3000。k<=10000。命令条数n不
		超过1000。
	输出格式：
		输出k行，即前k个事件的Q_num。
*/
