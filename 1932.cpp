#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long d[501][501];

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		vector<int> temp(i + 1);
		for (int j = 1; j <= i; j++)
		{
			cin >> temp[j];
		}
		v[i] = temp;
	}
	d[1][1] = v[1][1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1)
				d[i][j] = d[i - 1][j] + v[i][j];
			else
				d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + v[i][j];
		}
	}
	int maxnum = 0;
	for (int i = 1; i <= n; i++)
		if (maxnum < d[n][i])
			maxnum = d[n][i];
	cout << maxnum << "\n";
}