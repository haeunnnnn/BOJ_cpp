#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length();)
	{
		if (s[i] == '<')
		{
			while (s[i] != '>')
				i++;
			i++;
		}
		else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
		{
			int j = i;
			string str = "";
			while (s[i] != ' ' && s[i] != '<' && i < s.length())
			{
				str += s[i];
				i++;
			}
			reverse(str.begin(), str.end());
			for (int k = 0; k < str.length(); k++, j++)
				s[j] = str[k];
		}
		else i++;
	}
	cout << s << "\n";
}