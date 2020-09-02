#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long d[1001][1001];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		d[i][0] = d[i][i] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			d[i][j] = (d[i - 1][j - 1] + d[i - 1][j]) % 10007;
		}
	}
	cout << d[n][k] << "\n";
}