#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

queue<pair<int, int>> q;
bool ch[200001];

int main()
{
	int n, k;
	cin >> n >> k;
	q.push(make_pair(n, 0));
	ch[n] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int t = q.front().second;
		q.pop();
		if (x == k)
		{
			cout << t << "\n";
			break;
		}
		int x1 = x * 2;
		if (x1 >= 0 && x1 <= 200000 && !ch[x1])
		{
			ch[x1] = true;
			q.push(make_pair(x1, t));
		}

		// x*2를 따로 빼서 예외적으로 처리하지 않는 이상 
		// *2 -1 +1 순서여야함 
		// 그래야 작은 가중치부터 먼저 큐에서 나옴

		int x3 = x - 1;
		if (x3 >= 0 && x3 <= 200000 && !ch[x3])
		{
			ch[x3] = true;
			q.push(make_pair(x3, t + 1));
		}

		int x2 = x + 1;
		if (x2 >= 0 && x2 <= 200000 && !ch[x2])
		{
			ch[x2] = true;
			q.push(make_pair(x2, t + 1));
		}

	}
}