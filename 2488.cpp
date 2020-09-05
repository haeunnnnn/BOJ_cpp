#include <iostream>
#include <queue>

using namespace std;

int g[101][101];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0,0,1,-1 };

int main()
{
	int n;
	cin >> n;
	int minh = 987654321, maxh = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> g[i][j];
			if (g[i][j] < minh)
				minh = g[i][j];
			if (g[i][j] > maxh)
				maxh = g[i][j];
		}
	}
	int maxnum = 0;

	for (int h = 0; h <= maxh; h++)
	{
		int num = 1;
		int ch[101][101] = { 0, };
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (g[i][j] <= h)
					ch[i][j] = -1;
				else
				{
					if (ch[i][j]) continue;
					q.push(make_pair(i, j));
					ch[i][j] = num++;
					while (!q.empty())
					{
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						for (int k = 0; k < 4; k++)
						{
							int xx = x + dx[k];
							int yy = y + dy[k];
							if (xx < 0 || yy < 0 || xx >= n || yy >= n || ch[xx][yy] || g[xx][yy] <= h)
								continue;
							ch[xx][yy] = ch[x][y];
							q.push(make_pair(xx, yy));
						}
					}
				}
			}
		}
		if (maxnum < num - 1) maxnum = num - 1;
	}
	cout << maxnum << "\n";
}