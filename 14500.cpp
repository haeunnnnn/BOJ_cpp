#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

int p[501][501];
int dx[] = { 0,0,1 };
int dy[] = { 1,-1,0 };
int max_num;
int n, m;
bool ch[501][501];

void check_up(int x, int y) // で
{
	if (x - 1 < 0 || y < 0 || x >= n || y + 2 >= m)
		return;
	int num = p[x][y] + p[x][y + 1] + p[x][y + 2] + p[x - 1][y + 1];
	if (max_num < num)
		max_num = num;
}

void check_right(int x, int y) // た
{
	if (x < 0 || y < 0 || x + 2 >= n || y + 1 >= m)
		return;
	int num = p[x][y] + p[x + 1][y] + p[x + 1][y + 1] + p[x + 2][y];
	if (max_num < num)
		max_num = num;
}

void check_down(int x, int y) // ぬ
{
	if (x < 0 || y < 0 || x + 1 >= n || y + 2 >= m)
		return;
	int num = p[x][y] + p[x][y + 1] + p[x + 1][y + 1] + p[x][y + 2];
	if (max_num < num)
		max_num = num;
}

void check_left(int x, int y) // っ
{
	if (x - 1 < 0 || y < 0 || x + 1 >= n || y + 1 >= m)
		return;
	int num = p[x][y] + p[x][y + 1] + p[x - 1][y + 1] + p[x + 1][y + 1];
	if (max_num < num)
		max_num = num;
}

void dfs(int x, int y, int cnt, int num)
{

	if (cnt == 4)
	{
		if (max_num < num)
			max_num = num;
		return;
	}
	for (int k = 0; k < 3; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (ch[nx][ny]) continue;
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
		int x = p[nx][ny];
		ch[nx][ny] = true;
		dfs(nx, ny, cnt + 1, num + x);
		ch[nx][ny] = false;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> p[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dfs(i, j, 0, 0);
			check_down(i, j);
			check_left(i, j);
			check_up(i, j);
			check_right(i, j);
		}
	}
	cout << max_num << "\n";
}

