#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<char> v;
vector<string> ans;

int main()
{
	int l, c;
	cin >> l >> c;

	for (int i = 0; i < c; i++)
	{
		char temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	vector<bool> vec;
	for (int i = 0; i < c - l; i++)
		vec.push_back(false);
	for (int i = 0; i < l; i++)
		vec.push_back(true);
	do
	{
		string str = "";
		for (int i = 0; i < c; i++)
		{
			if (vec[i])
			{
				str += v[i];
			}
		}
		int a = 0, b = 0;
		for (int i = 0; i < l; i++)
		{
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
				a++;
			else b++;
		}
		if (a >= 1 && b >= 2)
			ans.push_back(str);
	} while (next_permutation(vec.begin(), vec.end()));
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
}