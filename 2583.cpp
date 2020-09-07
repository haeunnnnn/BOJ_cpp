#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int g[101][101];
bool ch[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int cnt;
vector<int> v;
int n, m;

void dfs(int x, int y)
{
	cnt++;
	ch[x][y] = true;

	for (int k = 0; k < 4; k++)
	{
		int xx = x + dx[k];
		int yy = y + dy[k];
		if (ch[xx][yy] || xx < 0 || yy < 0 || xx >= m || yy >= n) continue;
		dfs(xx, yy);
	}
}

int main()
{
	int k;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++)
		{
			for (int j = x1; j < x2; j++)
			{
				ch[i][j] = true;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ch[i][j]) continue;
			cnt = 0;
			dfs(i, j);
			v.push_back(cnt);
		}
	}
	cout << v.size() << "\n";
	sort(v.begin(), v.end());
	for (int i = 0; i < (int)v.size(); i++)
		cout << v[i] << " ";


}