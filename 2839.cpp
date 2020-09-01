#include <iostream>
#include <algorithm>
using namespace std;

int d[5001];

// BOJ 2839 DP·Î Ç®ÀÌ

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		d[i] = 9999;

	d[3] = 1;
	d[5] = 1;

	for (int i = 6; i <= n; i++)
	{
		d[i] = min(d[i - 3], d[i - 5]) + 1;
	}
	if (d[n] >= 9999) cout << -1 << "\n";
	else cout << d[n] << "\n";
}
