#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;
	int k;
	int sum = 0;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int n;
		cin >> n;
		if (n == 0)
			v.pop_back();
		else v.push_back(n);
	}
	for (int i = 0; i < (int)v.size(); i++)
		sum += v[i];
	cout << sum << "\n";
}