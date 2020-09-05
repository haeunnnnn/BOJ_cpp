#include <iostream>
#include <queue>

using namespace std;

vector<int> g[101];
int d[101];

int main()
{
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	queue<int> q;
	q.push(a);
	d[a] = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < g[x].size(); i++)
		{
			int y = g[x][i];
			if (d[y]) continue;
			d[y] = d[x] + 1;
			q.push(y);
		}
	}
	if (d[b] == 0) cout << -1 << "\n";
	else cout << d[b] - 1 << "\n";
}