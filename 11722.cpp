#include <iostream>
#include <vector>
using namespace std;

int d[1001];

int main()
{
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = n; i >= 1; i--)
	{
		d[i] = 1;
		for (int j = n; j > i; j--)
		{
			if (v[j] < v[i] && d[i] < d[j] + 1)
				d[i] = d[j] + 1;
		}
	}
	int maxnum = 0;
	for (int i = 1; i <= n; i++)
		if (d[i] > maxnum)
			maxnum = d[i];
	cout << maxnum << "\n";
}