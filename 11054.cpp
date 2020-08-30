#include <iostream>
#include <vector>

using namespace std;

int d1[1001];
int d2[1001];

int main()
{
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i <= n; i++)
	{
		d1[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (v[j] < v[i] && d1[i] < d1[j] + 1)
				d1[i] = d1[j] + 1;
		}
	}

	for (int i = n; i >= 1; i--)
	{
		d2[i] = 1;
		for (int j = n; j > i; j--)
		{
			if (v[j] < v[i] && d2[i] < d2[j] + 1)
				d2[i] = d2[j] + 1;
		}
	}
	int maxnum = 0;
	for (int i = 1; i <= n; i++)
		if (maxnum < d1[i] + d2[i] - 1)
			maxnum = d1[i] + d2[i] - 1;
	cout << maxnum << "\n";
}