#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long d[1000001];

int main()
{
	int n;
	cin >> n;
	d[1] = 1; // 1
	d[2] = 2; // 00 11
	for (int i = 3; i <= n; i++)
		d[i] = (d[i - 1] + d[i - 2]) % 15746;
	cout << d[n] << "\n";
}