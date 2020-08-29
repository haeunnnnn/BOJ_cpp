#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

long long ary[1000001][2];
long long d[1000001][3];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		memset(d, 0, sizeof(d));
		memset(ary, 0, sizeof(ary));
		int n;
		cin >> n;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> ary[j][i];
			}
		}
		d[0][0] = d[0][1] = d[0][2] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (j == 0) // ¾È¶âÀ½
					d[i][j] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
				else if (j == 1) // À§ÂÊ ¶âÀ½
					d[i][j] = max(d[i - 1][0], d[i - 1][2]) + ary[i][0];
				//¾Æ·¡¶âÀ½
				else if (j == 2)
					d[i][j] = max(d[i - 1][0], d[i - 1][1]) + ary[i][1];

			}
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = max(max(ans, d[i][0]), max(d[i][1], d[i][2]));
		}
		cout << ans << endl;


	}
}