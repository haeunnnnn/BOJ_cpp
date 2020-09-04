#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	int cnt = 0;
	cin >> n;
	while (n--)
	{
		bool f = true;
		bool ch[30] = { 0, };
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			if (ch[str[i] - 'a'])
			{
				f = false;
				break;
			}
			else
			{
				char temp = str[i];
				ch[str[i] - 'a'] = true;
				while (true)
				{
					if (temp != str[++i])
					{
						i--;
						break;
					}
				}
			}

		}
		if (f) cnt++;

	}
	cout << cnt << "\n";
}