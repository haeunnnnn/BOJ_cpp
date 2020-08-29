#include <iostream>

using namespace std;

long long d[91][2];
//int d[91];

int main()
{
	int n;
	cin >> n;
	d[1][1] = 1;
	d[1][0] = 0;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (j == 1)
			{
				d[i][j] = d[i - 1][0];
			}
			else
			{
				d[i][j] = d[i - 1][0] + d[i - 1][1];
			}
		}
	}
	cout << d[n][0] + d[n][1] << endl;
}