#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int map[9][9];
int temp[9][9];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int>> emp;
vector<pair<int, int>> virus;
bool ch[9][9];
int n, m;
int maxnum;

void find_safety()
{
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
				ans++;
		}
	}
	if (maxnum < ans)
		maxnum = ans;
}

void bfs()
{
	memset(ch, false, sizeof(ch));
	queue<pair<int, int>> q;
	for (auto i : virus)
	{
		q.push(i);
		ch[i.first][i.second] = true;
	}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int xx = x + dx[k];
			int yy = y + dy[k];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m || ch[xx][yy])
				continue;
			if (map[xx][yy] == 1) continue;
			map[xx][yy] = 2;
			ch[xx][yy] = true;
			q.push(make_pair(xx, yy));
		}
	}

}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
			{
				emp.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 2)
			{
				virus.push_back(make_pair(i, j));
			}
		}
	}
	vector<int> v(emp.size() - 3, 0);
	for (int i = 0; i < 3; i++)
		v.push_back(1);
	do
	{
		memcpy(temp, map, sizeof(map));
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i])
			{
				int x = emp[i].first;
				int y = emp[i].second;
				map[x][y] = 1;
			}
		}
		bfs();
		find_safety();
		memcpy(map, temp, sizeof(map));
	} while (next_permutation(v.begin(), v.end()));

	cout << maxnum << "\n";
}