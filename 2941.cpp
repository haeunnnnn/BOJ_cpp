#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int cnt = 0;
	for (int i = 0; i < str.length();)
	{
		if (str[i] == 'c')
		{
			if (str[i + 1] == '=' || str[i + 1] == '-')
			{
				i += 2;
			}
			else
			{
				i++;
			}
		}
		else if (str[i] == 'd')
		{
			if (str[i + 1] == '-')
			{
				i += 2;
			}
			else if (str[i + 1] == 'z' && str[i + 2] == '=')
			{
				i += 3;
			}
			else i++;
		}
		else if (str[i] == 'l' && str[i + 1] == 'j')
		{
			i += 2;
		}
		else if (str[i] == 'n' && str[i + 1] == 'j')
		{
			i += 2;
		}
		else if (str[i] == 's' && str[i + 1] == '=')
		{
			i += 2;
		}
		else if (str[i] == 'z' && str[i + 1] == '=')
		{
			i += 2;
		}
		else i++;
		cnt++;
	}
	cout << cnt << "\n";
}