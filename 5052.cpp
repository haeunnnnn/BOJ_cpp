#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool cmp(string a, string b)
{
	return a.length() < b.length();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<string> v;
		for (int i = 0; i < n; i++)
		{
			string tel;
			cin >> tel;
			v.push_back(tel);
		}
		sort(v.begin(), v.end());
		bool flag = true;
		for (int i = 0; i < v.size() - 1; i++)
		{
			if (v[i] == v[i + 1].substr(0, v[i].length()))
			{
				flag = false;
				break;
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
}