#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int miro[1001][1001];
long long d[1001][1001];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> miro[i][j];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if(i==1 && j==1)
				d[i][j] = miro[1][1];
			else d[i][j] = max(d[i - 1][j], max(d[i][j - 1], d[i - 1][j - 1])) + miro[i][j];
		}
	}
	cout << d[n][m] << "\n";
}