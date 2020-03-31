#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int num[4][4000];
int n;
vector<int> v1;
vector<int> v2;
bool flag = false;
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> n;
	long long cnt = 0;
	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> num[j][i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v1.push_back(num[0][i] + num[1][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v2.push_back(num[2][i] + num[3][j]);
		}
	}
	sort(v1.begin(), v1.end(),greater<int>());
	sort(v2.begin(), v2.end(),greater<int>());
	int idx = v2.size() - 1;
	for (int i = 0; i < v1.size(); i++)
	{
		while (v1[i] + v2[idx] < 0)
		{
			if (idx == 0)
			{
				flag = true;
				break;
			}
			idx--;
		}
		if (v1[i] + v2[idx] == 0)
		{
			int t1 = idx-1;
			int t2 = i+1;
			long long c1 = 1;
			long long c2 = 1;
			while (v1[i]==v1[t2])
			{
				c1++;
				if (t2 == v1.size()-1)
				{
					flag = true;
					break;
				}
				t2++;
			}
			while (v2[idx] == v2[t1])
			{
				c2++;
				if (t1 == 0)
				{
					flag = true;
					break;
				}
				t1--;
			}
			cnt += c1 * c2;
			idx = t1;
			i = t2-1;
		}
		if (flag)
			break;
	}

	cout<<cnt;
}