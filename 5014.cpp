#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int f, s, g, u, d;
queue<int> q;
long long ch[1000001];

int main()
{
	memset(ch, -1, sizeof(ch));
	cin >> f >> s >> g >> u >> d;
	q.push(s);
	ch[s] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		int y = x + u;
		if (y <= f && ch[y] < 0)
		{
			ch[y] = ch[x] + 1;
			q.push(y);
		}
		int z = x - d;
		if (z >= 1 && ch[z] < 0)
		{
			ch[z] = ch[x] + 1;
			q.push(z);
		}
	}
	if (ch[g] < 0) cout << "use the stairs\n";
	else cout << ch[g] << "\n";
}