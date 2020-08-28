#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		vector<int> v;
		int n;
		cin >> n;
		v.push_back(0);
		v.push_back(1);
		v.push_back(2);
		v.push_back(4);
		for (int i = 4; i <= n; i++)
		{
			v.push_back(v[i - 1] + v[i - 2] + v[i - 3]);
		}
		cout << v[n] << endl;
	}
}