#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> v;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		string s = str.substr(i);
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < (int)v.size(); i++)
	{
		cout << v[i] << "\n";
	}
}