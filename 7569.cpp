#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };

int g[101][101][101];
queue<pair<int, pair<int, int>>> q;
int ch[101][101][101];

int main()
{
	int m, n, h;
	cin >> m >> n >> h;
	memset(ch, -1, sizeof(ch));
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> g[i][j][k];
				if (g[i][j][k] == 1)
				{
					q.push(make_pair(i, make_pair(j, k)));
					ch[i][j][k] = 0;
				}
			}
		}
	}
	if (q.empty())
	{
		cout << 0 << "\n";
		return 0;
	}
	// 1은 익은, 0은 안익은 -1은 토마토 x
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second.first;
		int z = q.front().second.second;
		q.pop();
		for (int k = 0; k < 6; k++)
		{
			int xx = x + dx[k];
			int yy = y + dy[k];
			int zz = z + dz[k];
			if (xx < 0 || yy < 0 || zz < 0 || xx >= h || yy >= n || zz >= m)
				continue;
			if (ch[xx][yy][zz] >= 0 || g[xx][yy][zz] == -1)
				continue;
			ch[xx][yy][zz] = ch[x][y][z] + 1;
			q.push(make_pair(xx, make_pair(yy, zz)));
		}
	}
	int maxnum = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{

				if (g[i][j][k] == 0 && ch[i][j][k] == -1)
				{
					cout << -1 << "\n";
					return 0;
				}
				if (maxnum < ch[i][j][k])
					maxnum = ch[i][j][k];
			}
		}
	}
	cout << maxnum << "\n";
	return 0;
}