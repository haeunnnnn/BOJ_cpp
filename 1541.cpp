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
		// �ּڰ��� ����� ���ؼ��� �������� ��� ���� �����Ѵ�.
		// �׷��� -�� ���� ���ķδ� ���δ� �������� �ȴ�.
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