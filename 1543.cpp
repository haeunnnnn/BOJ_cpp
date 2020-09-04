#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str, word;
	getline(cin, str); //공백도 가능
	getline(cin, word);
	int cnt = 0;
	int i = 0;
	for (i; i < str.length();)
	{
		i = str.find(word, i);
		if (i == -1) break;
		i += word.length();
		cnt++;
	}
	cout << cnt << "\n";
}