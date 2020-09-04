#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long long d[1001][1001];

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	for (int i = 1; i <= str1.length(); i++)
	{
		for (int j = 1; j <= str2.length(); j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			else
			{
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
			}
		}
	}
	int ans = d[str1.length()][str2.length()];
	if (ans == 0)
		cout << 0 << "\n";
	else
	{
		cout << ans << "\n";
		string s = "";
		int x = str1.length();
		int y = str2.length();
		while (x >= 1 && y >= 1)
		{
			if (d[x][y] == d[x - 1][y])
				x--;
			else if (d[x][y] == d[x][y - 1])
				y--;
			else
			{
				s += str1[x - 1];
				x--, y--;
			}
		}
		reverse(s.begin(), s.end());
		cout << s << "\n";
	}
}