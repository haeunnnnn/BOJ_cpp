#include <iostream>
#include <string>

using namespace std;

int minnum = 987654321;
bool alpa[30];

int calc(string a, string b, int n)
{
	int cnt = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != b[i + n])
			cnt++;
	}
	return cnt;
}


int main()
{
	string a, b;
	cin >> a >> b;
	int sub = b.length() - a.length();
	if (sub == 0)
	{
		cout << calc(a, b, 0) << "\n";
		return 0;
	}
	else
	{
		for (int i = 0; i <= sub; i++)
		{
			int res = calc(a, b, i);
			if (minnum > res)
				minnum = res;
		}
	}
	cout << minnum << "\n";
}