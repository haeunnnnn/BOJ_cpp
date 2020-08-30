#include <iostream>
#include <vector>
using namespace std;

int d[100001];

int main()
{
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	d[1] = v[1];
	for (int i = 2; i <= n; i++)
	{
		d[i] = v[i];
		if (d[i] < d[i - 1] + v[i])
			d[i] = d[i - 1] + v[i];
	}
	int maxnum = -99999999;
	for (int i = 1; i <= n; i++)
		if (maxnum < d[i])
			maxnum = d[i];
	cout << maxnum << "\n";
}