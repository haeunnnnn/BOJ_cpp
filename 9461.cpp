#include <iostream>

using namespace std;

long long d[101] = { 0, };

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		d[1] = 1;
		d[2] = 1;
		d[3] = 1;
		d[4] = 2;
		d[5] = 2;
		for (int i = 6; i <= n; i++)
		{
			d[i] = d[i - 1] + d[i - 5];
		}
		cout << d[n] << "\n";
	}
}

/*
p[1] 1
p[2] 1
p[3] 1
p[4] 1+1(2)
p[5] 2
p[6] 1+2 = 3
p[7] 1+3 = 4
p[8] 1+4 = 5
p[9] 2+5 = 7
p[10] 2+7 = 9
p[11] 3+9 = 12
p[12] 4+12

*/