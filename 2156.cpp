#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long d[10001];

int main()
{
	int n;
	cin >> n;
	vector<long long> v(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	d[1] = v[1];
	d[2] = v[1] + v[2];
	for (int i = 3; i <= n; i++)
	{
		d[i] = max(d[i - 2] + v[i], d[i - 3] + v[i - 1] + v[i]);
		d[i] = max(d[i - 1], d[i]);
	}
	cout << d[n] << "\n";
}