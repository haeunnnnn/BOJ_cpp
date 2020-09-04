#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
	vector<char> oper;
	vector<int> num;
	string str;
	string s = "";
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '-' || str[i] == '+')
		{
			oper.push_back(str[i]);
			num.push_back(stoi(s));
			s = "";
		}
		else
		{
			s += str[i];
		}
	}
	num.push_back(stoi(s));
	int res = num[0];
	bool flag = false;
	for (int i = 1; i < (int)num.size(); i++)
	{
		// 최솟값을 만들기 위해서는 덧셈끼리 모두 묶어 빼야한다.
		// 그래서 -가 나온 이후로는 전부다 빼버리면 된다.
		if (oper[i - 1] == '+' && !flag)
		{
			res += num[i];
		}
		else
		{
			flag = true;
			res -= num[i];
		}
	}
	cout << res << "\n";
}