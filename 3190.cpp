#include<deque>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
bool apple[101][101];
bool snake_YN[101][101];
int time;
deque <pair<int, int>> snake;

int main()
{
	int snake_dir = 0;
	int n;
	cin >> n;
	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		apple[x][y] = true;
	}

	snake.push_front(make_pair(1, 1));
	snake_YN[1][1] = true;

	vector<pair<int, char>> v;
	int l;
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int x;
		char c;
		cin >> x >> c;
		v.push_back(make_pair(x, c));
	}

	int idx = 0;
	//赣府 FRONT 部府 BACK
	while (true)
	{
		time++;
		int x = snake.front().first;
		int y = snake.front().second;
		int nx = x + dx[snake_dir];
		int ny = y + dy[snake_dir];
		if (nx <= 0 || ny <= 0 || nx > n || ny > n)
			break;
		if (snake_YN[nx][ny])
			break;
		snake.push_front(make_pair(nx, ny));
		snake_YN[nx][ny] = true;
		if (apple[nx][ny])
		{
			apple[nx][ny] = false;
		}
		else
		{
			// 部府 临捞扁
			snake_YN[snake.back().first][snake.back().second] = false;
			snake.pop_back();
		}
		if (idx < v.size() && v[idx].first == time)
		{
			if (v[idx].second == 'L')
			{
				snake_dir -= 1;
				if (snake_dir == -1)
					snake_dir = 3;
			}
			else
			{
				snake_dir += 1;
				if (snake_dir == 4)
					snake_dir = 0;
			}
			idx += 1;
		}
	}
	cout << time << "\n";
}