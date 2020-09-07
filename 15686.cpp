#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int minnum = 987654321;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			// 0�� ��ĭ 1�� �� 2�� ġŲ��
			if (temp == 2)
				chicken.push_back(make_pair(i, j));
			else if (temp == 1)
				house.push_back(make_pair(i, j));
		}
	}
	/*vector<int> v;
	for (int i = 0; i < chicken.size(); i++)
		v.push_back(i);*/
	vector<bool>vec;
	for (int i = 0; i < chicken.size() - m; i++)
		vec.push_back(0);
	for (int i = 0; i < m; i++)
		vec.push_back(1);
	do
	{
		vector<int>distance(house.size(), 987654321);
		//m���� ġŲ�� ����
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i]) //���õ� ġŲ��
			{
				for (int j = 0; j < house.size(); j++)
				{
					//���õ� ġŲ���� �� ���� �Ÿ�
					int x1 = house[j].first;
					int y1 = house[j].second;
					int x2 = chicken[i].first;
					int y2 = chicken[i].second;
					int d = abs(x1 - x2) + abs(y1 - y2);
					distance[j] = min(distance[j], d);
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < house.size(); i++)
		{
			sum += distance[i];
		}
		minnum = min(sum, minnum);
	} while (next_permutation(vec.begin(), vec.end()));
	cout << minnum << "\n";

}