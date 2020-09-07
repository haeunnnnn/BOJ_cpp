#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, s;
	cin >> n >> s;
	vector<int> num(n + 1);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	int cnt = 0;
	for (int k = 1; k <= n; k++) // k°³ ¼±ÅÃ
	{
		vector<int> v;
		for (int j = 0; j < n - k; j++)
			v.push_back(0);
		for (int j = 0; j < k; j++)
			v.push_back(1);
		do
		{
			int sum = 0;
			for (int i = 0; i < n; i++)
			{
				if (v[i])
					sum += num[i];
			}
			if (sum == s) cnt++;
		} while (next_permutation(v.begin(), v.end()));

	}
	cout << cnt << "\n";
}