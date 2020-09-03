#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000000
using namespace std;

int d[201][201];

int main()
{
	//d[x][y] = z; // x개의 수로 y를 만들 수 있는 방법 : z개
	int n, k;
	cin >> n >> k;
	for (int i = 0; i <= n; i++)
	{
		d[1][i] = 1;
	}
	for (int i = 0; i <= k; i++)
		d[i][0] = 1;

	for (int i = 2; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			d[i][j] = (d[i - 1][j] + d[i][j - 1]) % MOD;
		}
	}
	cout << d[k][n] << "\n";

}