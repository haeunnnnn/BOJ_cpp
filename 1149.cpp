#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long d[1001][3];
int ary[1001][3];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> ary[i][j];
		}
	}
	d[1][0] = ary[1][0];
	d[1][1] = ary[1][1];
	d[1][2] = ary[1][2];
	for (int i = 2; i <= n; i++)
	{
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + ary[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + ary[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + ary[i][2];
	}
	cout << min(d[n][0], min(d[n][1], d[n][2])) << "\n";
}