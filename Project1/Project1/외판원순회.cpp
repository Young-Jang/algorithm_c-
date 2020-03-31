#include<iostream>
#include<algorithm>

#define INF 987654321

using namespace std;
int n;
int map[16][16];
int dp[16][1<<16];
int mins = INF;
int res;

int find(int idx, int check)
{
	if (check == res)
	{
		if (map[idx][0])
		{
			return map[idx][0];
		}
		else
		{
			return INF;
		}
	}
	if (dp[idx][check]!=INF)
		return dp[idx][check];
	for (int i = 1; i < n; i++)
	{
		if (!((1 << i) & (check))&&map[idx][i])
		{
			dp[idx][check] = min(dp[idx][check], find(i,check|(1<<i))+map[idx][i]);
		}
	}
	return dp[idx][check];
}

int main()
{
	cin >> n;
	res = (1 << n) - 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 1 << n; j++)
		{
			dp[i][j] = INF;
		}
	}
	cout << find(0, 1);
}