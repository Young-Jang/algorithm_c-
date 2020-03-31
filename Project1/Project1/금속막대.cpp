#include<iostream>
#include<vector>

using namespace std;
int n;
int maxs = 0;

int m[21][2];
int check[21];
int dp[21];
vector<int> v;
vector<int> res;

int dfs(int cnt, int sz)
{
	for (int i = 0; i < n; i++)
	{
		if (sz == m[i][0] && !check[i])
		{
			check[i] = 1;
			v.push_back(i);
			dfs(cnt + 1, m[i][1]);
			v.erase(v.end()-1);
			check[i] = 0;
		}
	}
	if (cnt > maxs)
	{
		res.clear();
		for (int i = 0; i < v.size(); i++)
			res.push_back(v[i]);
		maxs = cnt;
	}
	return cnt;
}

int main()
{
	int T;
	cin >> T;
	for (int k = 1; k <= 10; k++)
	{
		maxs = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> m[i][0] >> m[i][1];
		}
		for (int i = 0; i < n; i++)
		{
			check[i] = 1;
			v.push_back(i);
			dfs(0, m[i][1]);
			v.erase(v.end()-1);
			check[i] = 0;
		}

		cout << "#" << k << " ";
		for (int i = 0; i < res.size(); i++)
			cout << m[res[i]][0] << " " << m[res[i]][1]<<" ";
		cout << "\n";
		v.clear();
	}
}