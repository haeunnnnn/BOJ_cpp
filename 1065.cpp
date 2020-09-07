#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n < 100)
	{
		cout << n << "\n";
		return 0;
	}
	int cnt = 99;
	for (int i = 100; i <= n; i++)
	{
		int x[4];
		bool f = true;
		int length = (i == 1000) ? 4 : 3;
		int t = pow(10, length - 1);
		int num = i;
		int l = length;
		int k = 0;
		while (l--)
		{
			x[k] = num / t;
			num -= x[k++] * t;
			t /= 10;
		}
		int d = x[1] - x[0];
		for (int j = 1; j < length - 1; j++)
		{
			if (d != x[j + 1] - x[j])
			{
				f = false;
			}
		}
		if (f) cnt++;
	}
	cout << cnt << "\n";
}