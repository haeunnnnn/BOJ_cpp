#include <iostream>
#include <vector>
using namespace std;

int d[1001];

int main()
{
	int maxnum = 0;
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++)
	{
		d[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (v[j] < v[i] && d[i] < d[j] + 1)
			{
				d[i] = d[j] + 1;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[i] > maxnum)
			maxnum = d[i];
	}
	cout << maxnum << "\n";
}