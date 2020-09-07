#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	vector<int> order(n, 0);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i].first > v[j].first && v[i].second > v[j].second)
				order[j]++;
		}
	}
	for (int i = 0; i < n; i++)
		cout << order[i] + 1 << " ";
}