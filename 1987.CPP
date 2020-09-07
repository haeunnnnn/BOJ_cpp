#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

char g[21][21];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int r, c;
bool ch[21][21];
bool alpa[26];
int maxcnt;

void dfs(int x, int y, int cnt)
{
	maxcnt = max(maxcnt, cnt);
	for (int k = 0; k < 4; k++)
	{
		int xx = x + dx[k];
		int yy = y + dy[k];
		if (xx < 0 || yy < 0 || xx >= r || yy >= c || ch[xx][yy] || alpa[g[xx][yy] - 'A'])continue;
		alpa[g[xx][yy] - 'A'] = true;
		ch[xx][yy] = true;
		dfs(xx, yy, cnt + 1);
		alpa[g[xx][yy] - 'A'] = false;
		ch[xx][yy] = false;
	}
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> g[i][j];
		}
	}
	alpa[g[0][0] - 'A'] = true;
	ch[0][0] = true;
	dfs(0, 0, 1);
	cout << maxcnt << "\n";
}