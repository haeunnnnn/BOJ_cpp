#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long> d(n + 1);
	d[0] = 0;
	d[1] = 1;
	for (int i = 2; i <= n; i++)
		d[i] = d[i - 1] + d[i - 2];
	cout << d[n] << "\n";
}