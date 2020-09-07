#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int s[21][21];
int n;
int minnum = 987654321;

int solve(vector<int>a, vector<int>b)
{
	int ascore = 0, bscore = 0;
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			ascore += s[a[i]][a[j]];
			bscore += s[b[i]][b[j]];
		}
	}
	return abs(ascore - bscore);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> s[i][j]; // i,j가 같은 팀에 속했을때 더해지는 능력
		}
	}
	vector<int> v;
	for (int i = 0; i < n / 2; i++)
		v.push_back(0);
	for (int i = 0; i < n / 2; i++)
		v.push_back(1);
	do
	{
		vector<int> a;
		vector<int>b;
		for (int i = 0; i < n; i++)
		{
			if (v[i]) a.push_back(i);
			else b.push_back(i);
		}
		minnum = min(solve(a, b), minnum);
	} while (next_permutation(v.begin(), v.end()));
	cout << minnum << "\n";
}