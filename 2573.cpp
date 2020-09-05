#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int g[301][301];
int temp[301][301];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> g[i][j];
		}
	}
	int year = 0;
	while (1)
	{
		year++;
		bool f = false;
		//¡÷∫Ø¿« ∫Ûƒ≠ ººº≠ ¿˙¿Â
		for (int i = 1; i < n - 1; i++)
		{
			for (int j = 1; j < m - 1; j++)
			{
				if (g[i][j] != 0)
				{
					f = true;
					int cnt = 0;
					for (int k = 0; k < 4; k++)
					{
						int x = i + dx[k];
						int y = j + dy[k];
						if (g[x][y] == 0)
							cnt++;
					}
					temp[i][j] = cnt;
				}
			}
		}
		if (!f)
		{
			cout << 0 << "\n";
			return 0;
		}

		// ¡÷∫Ø ∫Ûƒ≠∏∏≈≠ ª©¡÷±‚
		for (int i = 1; i < n - 1; i++)
		{
			for (int j = 1; j < m - 1; j++)
			{
				if (g[i][j] - temp[i][j] <= 0)
					g[i][j] = 0;
				else g[i][j] -= temp[i][j];
			}
		}


		memset(temp, 0, sizeof(temp));

		// BFS∑Œ ∏Óµ¢æÓ∏Æ¿Œ¡ˆ »Æ¿Œ
		queue<pair<int, int>> q;
		int ch[301][301] = { 0, };
		int num = 1;
		for (int i = 1; i < n - 1; i++)
		{
			for (int j = 1; j < m - 1; j++)
			{
				if (g[i][j] > 0)
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
							if (xx < 0 || xx >= n || yy < 0 || yy >= m || ch[xx][yy] || g[xx][yy] == 0)
								continue;
							ch[xx][yy] = ch[x][y];
							q.push(make_pair(xx, yy));
						}
					}
				}
			}
		}
		if (num > 2)
		{
			cout << year << "\n";
			break;
		}
	}
}