#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		// 서쪽에 n개 동쪽에 m개
		// mCn개의 다리 (n<=m이므로)
		// mCn = m-1Cn-1 + m-1Cn
		// 파스칼의 삼각형
		long long d[31][31] = { 0, };
		for (int i = 1; i <= m; i++)
			d[i][0] = d[i][i] = 1;
		for (int i = 2; i <= m; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
		cout << d[m][n] << "\n";
	}
}