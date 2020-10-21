#include <iostream>
using namespace std;
int map[21][21];
int dice[6];
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };

void move_dice(int num)
{
	//0위 1아래 2왼 3앞 4오 5뒤
	if (num == 1) // 동쪽으로 움직임
	{
		int temp = dice[4]; // 오른쪽 저장
		dice[4] = dice[0]; //위에 있던 숫자가 오른쪽 자리
		dice[0] = dice[2]; //왼족에 있던 숫자가 위에 자리로
		dice[2] = dice[1];
		dice[1] = temp;
	}
	else if (num == 2) //서쪽으로 움직임
	{
		int temp = dice[2];
		dice[2] = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[1];
		dice[1] = temp;
	}
	else if (num == 3) //북쪽으로 움직임
	{
		int temp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[5];
		dice[5] = temp;
	}
	else
	{
		int temp = dice[1];
		dice[1] = dice[3];
		dice[3] = dice[0];
		dice[0] = dice[5];
		dice[5] = temp;
	}
}

int main()
{
	int n, m, x, y, k;
	// 세로 가로 주사위좌표 명령의 개수
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	dice[1] = map[x][y];

	for (int i = 0; i < k; i++)
	{
		int kk;
		cin >> kk;
		int nx = x + dx[kk];
		int ny = y + dy[kk];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;
		move_dice(kk);
		x = nx;
		y = ny;
		if (map[x][y] == 0)
			map[x][y] = dice[1];
		else
		{
			dice[1] = map[x][y];
			map[x][y] = 0;
		}
		cout << dice[0] << "\n";
	}
}