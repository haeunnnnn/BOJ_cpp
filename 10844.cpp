#include <iostream>

using namespace std;

int d[101][101];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i < 10; i++)
		d[1][i] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0) d[i][0] = d[i - 1][1];
			else if (j == 9) d[i][9] = d[i - 1][8];
			else d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % 1000000000;
		}
	}
	long long sum = 0;
	for (int i = 0; i <= 9; i++)
		sum += d[n][i];
	cout << sum % 1000000000 << endl;
}