#include <iostream>
#include <string>
using namespace std;


int main()
{
	int num;
	cin >> num;
	int i = 665;
	int cnt = 0;
	while (i++)
	{
		string str = to_string(i);
		if (str.find("666") != -1)
			cnt++;
		if (cnt == num)
		{
			cout << str << "\n";
			break;
		}
	}

}
