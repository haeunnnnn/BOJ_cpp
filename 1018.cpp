#include <iostream>

using namespace std;

bool g[51][51];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char temp;
			cin >> temp;
			if (temp == 'W')
				g[i][j] = true; // »Ú
			else g[i][j] = false; // ∞À¡§
		}
	}
	int mincnt = 987654321;
	for (int k = 0; k < 2; k++)
	{
		int x = 0, y = 0;
		while (x <= n - 8 && y <= m - 8)
		{
			int cnt = 0;
			bool f = g[x][y];
			if (k == 1) f = !f;
			for (int i = x; i < x + 8; i++)
			{
				for (int j = y; j < y + 8; j++)
				{
					if (f != g[i][j]) cnt++;
					if (j != y + 7) f = !f;
				}
			}
			if (mincnt > cnt) mincnt = cnt;
			if (y == m - 8)
			{
				y = 0;
				x++;
			}
			else y++;
		}
	}
	cout << mincnt << "\n";
}