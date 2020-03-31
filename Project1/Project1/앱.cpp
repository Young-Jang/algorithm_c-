#include<iostream>
#include<algorithm>
#include<vector>

#define INF 987654321

using namespace std;

int n, m;
int a[100];
int c[100];
pair<double,int> cost[100];
int dp[101][10001];
int mins = INF;
vector<int> v;

bool cmp(pair<double, int>a, pair<double, int> b)
{
	if (a.first > b.first)
	{
		return true;
	}
	return false;
}

int main()
{
	int res = 0;
	int hap = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> c[i];
	int sz = n * 100;
	dp[0][c[0]] = a[0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= sz; j++)
		{
			if (j - c[i] >= 0)
			{
				dp[i][j] = dp[i - 1][j - c[i]] + a[i];
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (dp[i][j] >= m)
			{
				if (mins > j)
					mins = j;
			}
		}
	}
	cout << mins;
}